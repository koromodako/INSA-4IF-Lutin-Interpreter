#ifndef NUMBER_H
#define NUMBER_H

#include "src/interfaces/abstractexpression.h"

/**
 * @brief Cette classe représente une constante numérique
 */
class Number : public AbstractExpression
{
public:
    ~Number(){}
    /**
     * @brief Construit une nouvelle instance d'une constante numérique
     * @param value
     *      Valeur de la constante numérique
     */
    Number(int value);
    Number(Number & other);

    inline bool isNumber() { return true; }
    inline bool isVariable() { return false; }
    inline bool isBinaryExpression() { return false; }

    /**
     * @override
     * @see AbstractExpression::eval()
     */
    int eval(DataMap &dmap, bool & ok);
    /**
     * @override
     * @see AbstractExpression::simplify()
     */
    AbstractExpression * simplify(DataMap &dmap, bool &ok);
    /**
     * @override
     * @see AbstractExpression::stringify()
     */
    string stringify();

private:
    int _value;
};

#endif // NUMBER_H
