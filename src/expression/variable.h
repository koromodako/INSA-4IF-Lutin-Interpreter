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
    string _identifier;
};

#endif // VARIABLE_H
