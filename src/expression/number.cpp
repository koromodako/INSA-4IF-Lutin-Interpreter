#include "number.h"

Number::Number(int value) :
    AbstractExpression(), _value(value)
{}

int Number::eval(DataMap &dmap)
{
    /// \todo implement here
}

void Number::simplify(DataMap &dmap)
{
    /// \todo implement here
}

string Number::stringify()
{
    /// \todo implement here
}
