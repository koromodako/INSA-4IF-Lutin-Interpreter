#include "variable.h"

#include "number.h"

Variable::Variable(string identifier) :
    AbstractExpression(),
    _identifier(identifier)
{}

Variable::Variable(Variable &other) :
    _identifier(other._identifier)
{
}

double Variable::Eval(DataMap &dmap, bool &ok)
{
    ok = false;
    double value(0);
    DataMap::iterator d = dmap.find(_identifier);
    if(d != dmap.end()) {
        value = d->second.value;
        ok = true;
    }
    // sinon erreur : variable manquante dans le dictionnaire des mémoires
    return value;
}

AbstractExpression * Variable::Simplify(DataMap &dmap, bool & ok)
{
    ok = false;
    AbstractExpression * simplified = NULL;
    DataMap::iterator d = dmap.find(_identifier);
    if(d != dmap.end()) {
        // si la donnée est une constante on remplace la donnée par un nombre
        if(d->second.cst) {
            simplified = new Number(d->second.value);
        }
        // on retourne vrai car la valeur existe dans le dictionnaire des mémoires
        ok = true;
    }
    // sinon erreur : variable manquante dans le dictionnaire des mémoires
    return simplified;
}

string Variable::Stringify()
{
    return _identifier;
}
