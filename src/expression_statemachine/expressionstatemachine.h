#ifndef EXPRESSIONSTATEMACHINE_H
#define EXPRESSIONSTATEMACHINE_H

#include "src/interfaces/abstractstatemachine.h"
#include "src/interfaces/abstractexpression.h"

/**
 * @brief Automate d'analyse des expressions arithmétiques
 */
class ExpressionStateMachine : public AbstractStateMachine
{
public:
    /**
     * @brief Constructeur de la machine à états pour l'analyse des expressions
     * @param lexer
     *      Lexer pour l'analyse lexicale
     * @param dmap
     *      Dictionnaire des mémoires à remplir
     * @param instructions
     *      Liste d'instruction à remplir
     */
    ExpressionStateMachine(Lexer &lexer, DataMap &dmap, InstructionList &instructions);
    ~ExpressionStateMachine(){}

    /**
     * @brief Exécute la machine à états
     * @note le paramètre n'est pas utilisé
     */
    bool Run(AbstractState * initialState = NULL);
};

#endif // EXPRESSIONSTATEMACHINE_H
