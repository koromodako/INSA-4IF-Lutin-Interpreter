#ifndef EXPRESSIONFACTORY_H
#define EXPRESSIONFACTORY_H

#include "binaryexpression.h"
#include "variable.h"
#include "number.h"

/**
 * @brief Cette fabrique permet de construire un arbre d'expression à partir d'une liste de symboles
 */
class ExpressionFactory
{
public:
    /**
     * @brief Construction de l'arbre d'expression à partir de la liste de symboles passée en paramètre
     * @param symbols
     *      Liste de symboles
     * @return la racine de l'arbre
     * @warning la mémoire allouée par cette méthode doit être libérée par l'appelant
     */
    static AbstractExpression* MakeExpression(SymbolList & symbols);

protected:
    /**
     * @brief Transforme la liste de symboles (expression infixe) en une nouvelle liste de symboles (expression postfixe)
     * @param symbols
     *      Liste de symboles (expression infixe)
     * @return liste de symboles (expression postfixe)
     */
    static SymbolList infixToPostfix(SymbolList & symbols);
    /**
     * @brief Construit un arbre d'expression à partir de la liste de symboles (expression postfixe) passée en paramètre
     * @param postfix
     *      Liste de symboles (expression postfixe)
     * @return la racine de l'arbre
     * @warning la mémoire allouée par cette méthode doit être libérée par l'appelant
     */
    static AbstractExpression * postfixToExpr(SymbolList &postfix);
    /**
     * @brief Donne la priorité de l'opération correspondant au code de symbole passé en paramètre
     * @param code
     *      Code de symbole
     * @return Retourne 1 si le symbole n'est pas un opérateur, 2 pour les opérateurs additifs et 3 pour les opérateurs multiplicatifs
     */
    static int precedence(SymbolCode code);
    /**
     * @brief Alloue la mémoire pour la création d'un opérande de type variable ou nombre
     * @param s
     *      Symbole de l'opérande à créer
     * @return l'objet Variable ou Number alloué. Retourne NULL si le symbole ne correspond pas à un opérande
     */
    static AbstractExpression * makeOperand(Symbol s);
    /**
     * @brief Alloue la mémoire pour la création d'une opération binaire de type addition, soustraction, multiplication ou division
     * @param s
     *      Symbole de l'opérateur
     * @param left
     *      Opérande de gauche
     * @param right
     *      Opérande de droite
     * @return l'objet BinaryExpression alloué ou NULL si le symbole ne correspond pas à un opérateur
     */
    static AbstractExpression * makeOperation(Symbol s, AbstractExpression * left, AbstractExpression * right);

    friend class ExpressionFactoryTests;

private:
    // constructeurs privés : fabrique non instanciable
    ExpressionFactory(){}
    ExpressionFactory(ExpressionFactory&){}
};

#endif // EXPRESSIONFACTORY_H
