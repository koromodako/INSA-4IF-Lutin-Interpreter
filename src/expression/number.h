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

    /**
     * @override
     * @see AbstractExpression::eval()
     */
    int eval(DataMap &dmap);
    /**
     * @override
     * @see AbstractExpression::simplify()
     */
    void simplify(DataMap &dmap);
    /**
     * @override
     * @see AbstractExpression::stringify()
     */
    string stringify();

private:
    int _value;
};

#endif // NUMBER_H
