#include "expressionfactory.h"
#include "src/debug.h"

AbstractExpression* ExpressionFactory::MakeExpression(SymbolList &symbols)
{   // -- DEBUG -------------------------------------------
    DBG_PRT("input expr is : ");
    DBG_SYM_LIST(symbols);
    // -- DEBUG -------------------------------------------
    SymbolList postfix = infixToPostfix(symbols);
    // -- DEBUG -------------------------------------------
    DBG_PRT("postfix expr is : ");
    DBG_SYM_LIST(postfix);
    // -- DEBUG -------------------------------------------
    return postfixToExpr(postfix);
}

SymbolList ExpressionFactory::infixToPostfix(SymbolList &symbols)
{
    SymbolStack opStack;
    SymbolList postfix;
    for(SymbolList::iterator s = symbols.begin(); s != symbols.end(); ++s)
    {   if(s->code == S_ID || s->code == S_NUM)
        {   postfix.push_back(*s);
        }
        else if(s->code == S_PO)
        {   opStack.push(*s);
        }
        else if(s->code == S_PF)
        {   while(opStack.top().code != S_PO)
            {   postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.pop();
        }
        else
        {   while (!opStack.empty() && precedence(opStack.top().code) >= precedence(s->code))
            {   postfix.push_back(opStack.top());
                opStack.pop();
            }
            opStack.push(*s);
        }
    }
    while (!opStack.empty())
    {   postfix.push_back(opStack.top());
        opStack.pop();
    }
    // -- DEBUG ----------------------------------------
    //DBG_PRT("input expr is : ");
    //DBG_SYM_LIST(symbols);
    //DBG_PRT("postfix expr is : ");
    //DBG_SYM_LIST(postfix);
    // -- DEBUG ----------------------------------------
    return postfix;
}

AbstractExpression *ExpressionFactory::postfixToExpr(SymbolList &postfix)
{
    AbstractExpression * expr = NULL;
    stack<AbstractExpression*> exprStack;
    for(SymbolList::iterator s = postfix.begin(); s != postfix.end(); ++s)
    {   if(s->code == S_ID || s->code == S_NUM)
        {   exprStack.push(makeOperand(*s));
        }
        else if(s->code == S_PLUS || s->code == S_MINUS || s->code == S_MULT || s->code == S_DIV)
        {   // récupération des deux opérandes sur la pile
            AbstractExpression * right = exprStack.top();
            exprStack.pop();
            AbstractExpression * left = exprStack.top();
            exprStack.pop();
            // ajout de l'opération sur la pile
            exprStack.push(makeOperation(*s, left, right));
        }
        else
        {   ERROR("ExpressionFactory::postfixToExpr : unexpected symbol, skipped !");
        }
    }
    if(exprStack.size() == 1)
    {   expr = exprStack.top();
        exprStack.pop();
    }
    else
    {   ERROR("ExpressionFactory::postfixToExpr : exprStack size != 1 at end, cleaning and returning NULL");
    }
    return expr;
}

int ExpressionFactory::precedence(SymbolCode code)
{
    int prec = 1;
    switch (code) {
    case S_MULT:    prec = 3; break;
    case S_DIV:     prec = 3; break;
    case S_PLUS:    prec = 2; break;
    case S_MINUS:   prec = 2; break;
    default: break;
    }
    return prec;
}

AbstractExpression *ExpressionFactory::makeOperand(Symbol s)
{
    switch (s.code) {
    case S_ID:  return new Variable(s.buf);
    case S_NUM: return new Number(atof(s.buf.c_str()));
    default: ERROR("Expressionfactory::makeOperand failed, illegal symbol(code='"<<s.code<<"',buf='"<<s.buf<<"') : NULL returned"); break;
    }
    return NULL;
}

AbstractExpression *ExpressionFactory::makeOperation(Symbol s, AbstractExpression *left, AbstractExpression *right)
{
    switch (s.code) {
    case S_MULT:    return new BinaryExpression(BOP_MULT, left, right);
    case S_DIV:     return new BinaryExpression(BOP_DIV, left, right);
    case S_PLUS:    return new BinaryExpression(BOP_PLUS, left, right);
    case S_MINUS:   return new BinaryExpression(BOP_MINUS, left, right);
    default: ERROR("Expressionfactory::makeOperation failed, illegal symbol(code='"<<s.code<<"',buf='"<<s.buf<<"') : NULL returned"); break;
    }
    return NULL;
}

