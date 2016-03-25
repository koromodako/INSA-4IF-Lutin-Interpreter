#ifndef ABSTRACTEXPRESSION_H
#define ABSTRACTEXPRESSION_H

#include "src/types/types.h"
#include "src/types/datamap.h"

#include <set>
using namespace std;

/**
 * @brief Cette classe définit une expression arithmétique générique
 */
class AbstractExpression
{
public:
    virtual ~AbstractExpression(){}

    /**
     * @brief Retourne vrai si l'expression est un nombre
     * @see Number
     */
    virtual bool IsNumber() const = 0;
    /**
     * @brief Retourne vrai si l'expression est une opération binaire
     * @see BinaryExpression
     */
    virtual bool IsBinaryExpression() const = 0;
    /**
     * @brief Retourne vrai si l'expression est une variable
     * @see Variable
     */
    virtual bool IsVariable() const = 0;

    /**
     * @brief Remplit la liste avec toutes les variables utilisées dans l'expression
     * @param list
     */
    virtual void GetUsedVariables(set<string> &list) const = 0;

    /**
     * @brief Retourne la valeur évaluée de l'arbre
     * @param dmap
     *      Dictionnaire des mémoires
     * @param ok
     *      Si ok vaut 'false' après exécution, alors l'évaluation a échoué
     * @return
     */
    virtual double Eval(DataMap & dmap, bool & ok) const = 0;
    /**
     * @brief Simplifie l'expression arithmétique en réduisant l'arbre grâce aux opérations
     *          suivantes :
     *              - substitution des constantes,
     *              - calcul des expressions constantes,
     *              - élimination des éléments neutres
     * @param dmap
     *      Dictionnaire des mémoires du programme
     * @param ok
     *      Ce paramètre est utilisé pour savoir si l'évaluation a rencontré une erreur ou non
     * @return
     */
    virtual AbstractExpression * Simplify(DataMap & dmap, bool & ok) = 0;
    /**
     * @brief Construit la chaîne de caractères correspondant à l'expression arithmétique
     * @return
     */
    virtual string Stringify() const = 0;
    /**
     * @brief Permet d'indiquer si l'expression doit être parenthésée
     */
    inline void SetRequireParenthesis() { _requireParenthesis = true; }

protected:
    // constructeur protégé
    AbstractExpression();

protected:
    bool _requireParenthesis;
};

#endif // ABSTRACTEXPRESSION_H
