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
     * @brief Construit une nouvelle instance d'une operation à deux operandes
     * @param op
     *      Operateur entre les deux operandes
     * @param left
     *      Operande gauche
     * @param right
     *      Operande droite
     */
    BinaryExpression(BinaryOperator op, AbstractExpression * left, AbstractExpression * right);

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
    BinaryOperator _op;
    AbstractExpression * _left;
    AbstractExpression * _right;
};

#endif // BINARYEXPRESSION_H
