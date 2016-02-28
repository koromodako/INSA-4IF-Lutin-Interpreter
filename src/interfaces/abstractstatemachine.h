#ifndef ABSTRACTSTATEMACHINE_H
#define ABSTRACTSTATEMACHINE_H

#include "abstractstate.h"
#include <stack>

using namespace std;

/**
 * @brief Cette classe abstraite représente une machine à états pour l'analyse syntaxique quelconque
 */
class AbstractStateMachine
{
public:
    virtual ~AbstractStateMachine(){}

    /**
     * @brief Effectue la reduction souhaitée
     * @param symbole
     *      Symbole courant
     * @param state
     *      Nouvel état
     */
    virtual void reduce(int symbole, AbstractState * state);

    /**
     * @brief Effectue la recupération sur erreur s'il y a lieu ou place la machine à état dans un état d'erreur
     * @param symbole
     *      Symbole courant
     * @param state
     *      Nouvel état
     */
    virtual void unexpected(int symbole, AbstractState * state);

protected:
    AbstractStateMachine();

private:
    stack<string> _error_stack;         // pile des erreurs
    stack<int> _symbols_stack;          // pile des symboles
    stack<AbstractState*> _state_stack; // pile des états
};

#endif // ABSTRACTSTATEMACHINE_H
