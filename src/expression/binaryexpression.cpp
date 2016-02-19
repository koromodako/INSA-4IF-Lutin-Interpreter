#include "binaryexpression.h"

BinaryExpression::~BinaryExpression()
{
    // free memory
    delete _left;
    delete _right;
}

BinaryExpression::BinaryExpression(BinaryOperator op, AbstractExpression * left, AbstractExpression * right) :
    AbstractExpression(), _op(op), _left(left), _right(right)
{}

int BinaryExpression::eval(DataMap &dmap)
{
    /// \todo implement here
}

void BinaryExpression::simplify(DataMap &dmap)
{
    /// \todo implement here
}

string BinaryExpression::stringify()
{
    /// \todo implement here
}
