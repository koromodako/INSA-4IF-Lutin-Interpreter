#ifndef PROGRAMSTATEMACHINE_H
#define PROGRAMSTATEMACHINE_H

#include "../types/types.h"
#include "../interfaces/abstractstatemachine.h"

#include <list>

using namespace std;

/**
 * @brief Automate d'analyse de scripts lutin
 */
class ProgramStateMachine : public AbstractStateMachine
{
public:
    /**
     * @brief Constructeur de la machine à états d'analyse du programme
     * @param lexer
     *      Lexer pour l'analyse lexicale
     * @param dmap
     *      Dictionnaire des mémoires à remplir
     * @param instructions
     *      Liste d'instruction à remplir
     */
    ProgramStateMachine(Lexer & lexer, DataMap & dmap, InstructionList & instructions);
    ~ProgramStateMachine(){}

    /**
     * @brief Exécute la machine à états
     * @note le paramètre n'est pas utilisé
     */
    bool Run(AbstractState * initialState = NULL);
};

#endif // PROGRAMSTATEMACHINE_H
