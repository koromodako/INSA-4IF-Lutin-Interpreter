#include "number.h"

#include <sstream>

Number::Number(double value) :
    AbstractExpression(), _value(value)
{}

Number::Number(Number &other) :
    _value(other._value)
{
}

double Number::eval(DataMap &, bool &ok)
{
    ok = true;
    return _value;
}

AbstractExpression * Number::simplify(DataMap &, bool & ok)
{
    // Déjà simple
    ok = true;
    return NULL;
}

string Number::stringify()
{
    stringstream ss("");
    ss << _value;
    return ss.str();
}
