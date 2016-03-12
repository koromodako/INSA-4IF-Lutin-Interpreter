#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "binaryexpression.h"
#include "variable.h"
#include "number.h"

class ExpressionFactory
{
public:
    static AbstractExpression* MakeExpression(SymbolList & symbols);

protected:
    static SymbolList infixToPostfix(SymbolList & symbols);
    static AbstractExpression * postfixToExpr(SymbolList &postfix);
    static int precedence(SymbolCode code);
    static AbstractExpression * makeOperand(Symbol s);
    static AbstractExpression * makeOperation(Symbol s, AbstractExpression * left, AbstractExpression * right);

    friend class ExpressionFactoryTests;

private:
    ExpressionFactory(){}
};

#endif // EXPRESSIONFACTORY_H
