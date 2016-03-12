#ifndef ABSTRACTEXPRESSION_H
#define ABSTRACTEXPRESSION_H

#include "src/types/types.h"
#include "src/types/datamap.h"
using namespace std;

/**
 * @brief Cette classe définit une expression arithmétique générique
 */
class AbstractExpression
{
public:
    virtual ~AbstractExpression(){}

    /// \todo Trouver si on peut pas éviter ça,
    ///         pas en mettant un enum de type non plus bien sûr
    ///         mais en essayant de trouver une meilleure solution dans le simplify de BinaryExpression
    virtual bool IsNumber() = 0;
    virtual bool IsBinaryExpression() = 0;
    virtual bool IsVariable() = 0;

    /**
     * @brief Retourne la valeur calculée à partir de l'évaluation
     * @param dmap
     * @param ok
     * @return
     */
    virtual double Eval(DataMap & dmap, bool & ok) = 0;
    /**
     * @brief Simplifie l'expression arithmétique en réduisant l'arbre grâce aux opérations
     *          suivantes :
     *              - substitution des constantes,
     *              - calcul des expressions constantes,
     *              - élimination des éléments neutres
     * @param dmap
     *      Dictionnaire des mémoires du programme
     * @param ok
     *      Ce paramètre est utilisé pour savoir si l'évaluation à rencontré une erreur ou non
     * @return
     */
    virtual AbstractExpression * Simplify(DataMap & dmap, bool & ok) = 0;
    /**
     * @brief Construit la chaine de caractère correspondant à l'expression arithmétique
     * @return
     */
    virtual string Stringify() = 0;

    inline void SetRequireParenthesis() { _requireParenthesis = true; }

protected:
    AbstractExpression();

private:
    bool _requireParenthesis;
};

#endif // ABSTRACTEXPRESSION_H
