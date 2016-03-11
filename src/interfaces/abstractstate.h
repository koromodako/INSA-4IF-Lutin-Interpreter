#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <string>
#include "../types/types.h"
#include "abstractstatemachine.h"


using namespace std;
class AbstractStateMachine;
/**
 * @brief Cette classe abstraite représente un état quelconque d'une machine à états
 */
class AbstractState
{
public:
    enum TransitionResult
    {
        UNEXPECTED,
        REDUCED,
        PILED_UP
    };
    virtual ~AbstractState(){}
    /**
     * @brief Réalise la transition de l'état vers un autre état
     * @param machine
     *      Machine à états contenant l'état courant
     * @param symbol
     *      Symbole suivant
     * @return
     */
    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol) = 0;
    /**
     * @brief Retourne le nom de l'état courant
     * @return
     */
    inline const string & name() const { return _name; }

protected:
    AbstractState(const string & name);

private:
    string _name; // nom de l'état
};

#endif // ABSTRACTSTATE_H
