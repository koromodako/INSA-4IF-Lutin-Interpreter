#include "variable.h"

Variable::Variable(string identifier) :
    AbstractExpression(),
    _identifier(identifier)
{}

int Variable::eval(DataMap &dmap)
{
    /// \todo implement here
}

void Variable::simplify(DataMap &dmap)
{
    /// \todo implement here
}

string Variable::stringify()
{
    /// \todo implement here
}
