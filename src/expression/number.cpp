#include "number.h"

#include <sstream>

Number::Number(double value) :
    AbstractExpression(), _value(value)
{}

void Number::GetUsedVariables(set<string> &) const
{
}

double Number::Eval(DataMap &, bool &ok) const
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

string Number::Stringify() const
{
    stringstream ss("");
    ss << _value;
    return ss.str();
}
