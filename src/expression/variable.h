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
     * @see AbstractExpression::IsNumber()
     */
    inline bool IsNumber() const { return false; }
    /**
     * @override
     * @see AbstractExpression::IsVariable()
     */
    inline bool IsVariable() const { return true; }
    /**
     * @override
     * @see AbstractExpression::IsBinaryExpression()
     */
    inline bool IsBinaryExpression() const { return false; }

    /**
     * @override
     * @see AbstractExpression::GetUsedVariables()
     */
    void GetUsedVariables(set<string> &list) const;

    /**
     * @override
     * @see AbstractExpression::Eval()
     */
    double Eval(DataMap &dmap, bool & ok) const;
    /**
     * @override
     * @see AbstractExpression::Simplify()
     */
    AbstractExpression *Simplify(DataMap &dmap, bool &ok);
    /**
     * @override
     * @see AbstractExpression::Stringify()
     */
    string Stringify() const;

private:
    string _identifier; // identifiant
};

#endif // VARIABLE_H
