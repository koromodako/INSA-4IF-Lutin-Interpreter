#ifndef BINARYEXPRESSION_H
#define BINARYEXPRESSION_H

#include "src/interfaces/abstractexpression.h"

/**
 * @brief Cette classe représente une opération arithmétique à deux opérandes
 */
class BinaryExpression : public AbstractExpression
{
public:
    ~BinaryExpression();
    /**
     * @brief Construit une nouvelle instance d'une opération à deux opérandes
     * @param op
     *      Opérateur entre les deux opérandes
     * @param left
     *      Opérande gauche
     * @param right
     *      Opérande droite
     */
    BinaryExpression(BinaryOperator op, AbstractExpression * left, AbstractExpression * right);
    /**
     * @brief Constructeur de copie
     * @param other
     */
    BinaryExpression(BinaryExpression & other);

    /**
     * @override
     * @see AbstractExpression::IsNumber()
     */
    inline bool IsNumber() const { return false; }
    /**
     * @override
     * @see AbstractExpression::IsVariable()
     */
    inline bool IsVariable() const { return false; }
    /**
     * @override
     * @see AbstractExpression::IsBinaryExpression()
     */
    inline bool IsBinaryExpression() const { return true; }

    /**
     * @override
     * @see AbstractExpression::GetUsedVariables()
     */
    void GetUsedVariables(set<string> &list) const;

    /**
     * @override
     * @see AbstractExpression::Eval()
     */
    double Eval(DataMap &dmap, bool &ok) const;
    /**
     * @override
     * @see AbstractExpression::Simplify()
     */
    AbstractExpression * Simplify(DataMap &dmap, bool & ok);
    /**
     * @override
     * @see AbstractExpression::Stringify()
     */
    string Stringify() const;

private:
    BinaryOperator _op;            // opérateur
    AbstractExpression * _left;    // opérande de gauche
    AbstractExpression * _right;   // opérande de droite
};

#endif // BINARYEXPRESSION_H
