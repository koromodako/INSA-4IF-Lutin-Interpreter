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
    Number(double value);

    /**
     * @override
     * @see AbstractExpression::IsNumber()
     */
    inline bool IsNumber() const { return true; }
    /**
     * @override
     * @see AbstractExpression::IsVariable()
     */
    inline bool IsVariable() const { return false; }
    /**
     * @override
     * @see AbstractExpression::IsBinaryExpression()
     */
    inline bool IsBinaryExpression() const { return false; }

    /**
     * @override
     * @see AbstractExpression::GetUsedVariables()
     */
    void GetUsedVariables(set<string> &list) const;

    /**
     * @override
     * @see AbstractExpression::Eval()
     */
    double Eval(DataMap &dmap, bool & ok) const;
    /**
     * @override
     * @see AbstractExpression::Simplify()
     */
    AbstractExpression * Simplify(DataMap &dmap, bool &ok);
    /**
     * @override
     * @see AbstractExpression::Stringify()
     */
    string Stringify() const;

private:
    double _value; // valeur
};

#endif // NUMBER_H
