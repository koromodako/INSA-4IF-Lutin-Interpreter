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
    BinaryExpression(BinaryOperator op, AbstractExpression * left, AbstractExpression * right, bool hasParenthesisAround = false);
    BinaryExpression(BinaryExpression & other);

    inline bool IsNumber() { return false; }
    inline bool IsVariable() { return false; }
    inline bool IsBinaryExpression() { return true; }

    /**
     * @override
     * @see AbstractExpression::eval()
     */
    double Eval(DataMap &dmap, bool &ok);
    /**
     * @override
     * @see AbstractExpression::simplify()
     */
    AbstractExpression * Simplify(DataMap &dmap, bool & ok);
    /**
     * @override
     * @see AbstractExpression::stringify()
     */
    string Stringify();

private:
    bool _hasParenthesisAround;
    BinaryOperator _op;            // opérateur
    AbstractExpression * _left;    // opérande à gauche
    AbstractExpression * _right;   // opérande à droite
};

#endif // BINARYEXPRESSION_H
