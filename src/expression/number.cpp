#include "number.h"

#include <sstream>

Number::Number(double value) :
    AbstractExpression(), _value(value)
{}

Number::Number(Number &other) :
    _value(other._value)
{
}

double Number::Eval(DataMap &, bool &ok)
{
    ok = true;
    return _value;
}

AbstractExpression * Number::Simplify(DataMap &, bool & ok)
{
    // Déjà simple
    ok = true;
    return NULL;
}

string Number::Stringify()
{
    stringstream ss("");
    ss << _value;
    return ss.str();
}
