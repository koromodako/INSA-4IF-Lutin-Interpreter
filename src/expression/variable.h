#ifndef VARIABLE_H
#define VARIABLE_H

#include "src/interfaces/abstractexpression.h"

/**
 * @brief Cette classe représente une variable
 */
class Variable : public AbstractExpression
{
public:
    ~Variable(){}
    /**
     * @brief Construit une nouvelle instance d'une variable à partir de l'identifiant fourni
     * @param identifier
     *      Identifiant de la variable à construire
     */
    Variable(string identifier);
    Variable(Variable & other);

    inline bool isNumber() { return false; }
    inline bool isVariable() { return true; }
    inline bool isBinaryExpression() { return false; }

    /**
     * @override
     * @see AbstractExpression::eval()
     */
    double eval(DataMap &dmap, bool & ok);
    /**
     * @override
     * @see AbstractExpression::simplify()
     */
    AbstractExpression *simplify(DataMap &dmap, bool &ok);
    /**
     * @override
     * @see AbstractExpression::stringify()
     */
    string stringify();

private:
    string _identifier; // identifiant
};

#endif // VARIABLE_H
