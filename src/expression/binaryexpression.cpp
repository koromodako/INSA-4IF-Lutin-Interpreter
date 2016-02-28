#include "binaryexpression.h"

#include "number.h"
#include "variable.h"
#include <sstream>

#define ADD_PARENTHESIS

#define DEEP_COPY(original, copy) \
    if(original->isNumber()) { copy = new Number(*dynamic_cast<Number*>(original)); } \
    else if(original->isVariable()) { copy = new Variable(*dynamic_cast<Variable*>(original)); } \
    else if(original->isBinaryExpression()) { copy = new BinaryExpression(*dynamic_cast<BinaryExpression*>(original)); }

BinaryExpression::~BinaryExpression()
{
    // libération mémoire
    delete _left;
    delete _right;
}

BinaryExpression::BinaryExpression(BinaryOperator op, AbstractExpression * left, AbstractExpression * right) :
    AbstractExpression(), _op(op), _left(left), _right(right)
{}

BinaryExpression::BinaryExpression(BinaryExpression &other) :
    _op(other._op)
{
    // copie profonde de l'opérande à gauche !
    DEEP_COPY(other._left, _left)
    // copie profonde de l'opérande à droite !
    DEEP_COPY(other._right, _right)
}

double BinaryExpression::eval(DataMap &dmap, bool & ok)
{
    double value(0);
    double left_eval = _left->eval(dmap, ok);
    if(ok)
    {   double right_eval = _right->eval(dmap, ok);
        // si les deux évaluations précédentes sont valides
        if(ok)
        {   // on effectue le calcul en fonction de l'opération
            switch (_op) {
            case BOP_PLUS:
                value = left_eval + right_eval;
                break;
            case BOP_MINUS:
                value = left_eval - right_eval;
                break;
            case BOP_MULT:
                value = left_eval * right_eval;
                break;
            case BOP_DIV:
                if(right_eval != 0)
                {   value = left_eval / right_eval;
                }
                else
                {   ok = false; // on baisse le flag ok pour signaler l'erreur (division par zero)
                }
                break;
            }
        }
    }
    return value;
}

AbstractExpression *BinaryExpression::simplify(DataMap &dmap, bool &ok)
{
    AbstractExpression * simplified = NULL;
    // on esssaie d'abord de simplifier les deux opérandes
    AbstractExpression * left_simplified = _left->simplify(dmap, ok);
    if(ok)
    {   AbstractExpression * right_simplified = _right->simplify(dmap, ok);
        if(ok)
        {   if(left_simplified != NULL)
            {   // on libère la mémoire de l'ancien opérande de gauche
                delete _left; // (<!> il faut faire des copies profondes à cause de cette ligne <!>)
                // on associe la nouvelle opérande de gauche au calcul
                _left = left_simplified;
            }
            if(right_simplified != NULL)
            {   // on libère la mémoire de l'ancien opérande de droite
                delete _right; // (<!> il faut faire des copies profondes à cause de cette ligne <!>)
                // on associe la nouvelle opérande de droite au calcul
                _right = right_simplified;
            }
            // on essaie ensuite de simplifier le calcul
            // si les deux opérandes sont des nombres
            if(_left->isNumber() && _right->isNumber())
            {   // on simplifie le calcul en évaluant ce dernier
                int value = eval(dmap, ok);
                // si l'évaluation s'est bien déroulée
                if(ok)
                {   simplified = new Number(value);
                }
            }
            else // sinon on cherche les éléments neutres
            {   bool useless_ok;
                switch (_op) {
                case BOP_PLUS:
                    if(_left->isNumber() && _left->eval(dmap, useless_ok) == 0)
                    {   // copie profonde
                        DEEP_COPY(_right, simplified)
                    }
                    else if(_right->isNumber() && _right->eval(dmap, useless_ok) == 0)
                    {   // copie profonde
                        DEEP_COPY(_left, simplified)
                    }
                    break;
                case BOP_MINUS:
                    if(_right->isNumber() && _right->eval(dmap, useless_ok) == 0)
                    {   // copie profonde
                        DEEP_COPY(_left, simplified)
                    }
                    break;
                case BOP_MULT:
                    if(_left->isNumber() && _left->eval(dmap, useless_ok) == 1)
                    {   // copie profonde
                        DEEP_COPY(_right, simplified)
                    }
                    else if(_right->isNumber() && _right->eval(dmap, useless_ok) == 1)
                    {   // copie profonde
                        DEEP_COPY(_left, simplified)
                    }
                    break;
                case BOP_DIV:
                    if(_right->isNumber() && _right->eval(dmap, useless_ok) == 1)
                    {   // copie profonde
                        DEEP_COPY(_left, simplified)
                    }
                    break;
                }
            }
        }
    }
    return simplified;
}

string BinaryExpression::stringify()
{
    stringstream ss("");
#ifdef ADD_PARENTHESIS
    ss << "(";
#endif
    ss << _left->stringify();
    switch (_op) {
    case BOP_PLUS:  ss << '+'; break;
    case BOP_MINUS: ss << '-'; break;
    case BOP_MULT:  ss << '*'; break;
    case BOP_DIV:   ss << '/'; break;
    }
    ss << _right->stringify();
#ifdef ADD_PARENTHESIS
    ss << ")";
#endif
    return ss.str();
}
