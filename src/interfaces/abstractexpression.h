#ifndef ABSTRACTEXPRESSION_H
#define ABSTRACTEXPRESSION_H

#include "src/types.h"

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
    virtual bool isNumber() = 0;
    virtual bool isBinaryExpression() = 0;
    virtual bool isVariable() = 0;

    /**
     * @brief Retourne la valeur calculée à partir de l'évaluation
     * @param dmap
     * @param ok
     * @return
     */
    virtual double eval(DataMap & dmap, bool & ok) = 0;
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
    virtual AbstractExpression * simplify(DataMap & dmap, bool & ok) = 0;
    /**
     * @brief Construit la chaine de caractère correspondant à l'expression arithmétique
     * @return
     */
    virtual string stringify() = 0;

protected:
    AbstractExpression();

};

#endif // ABSTRACTEXPRESSION_H
