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
     * @brief Affiche le nom de l'état
     */
    void print() const;
    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol)=0;

protected:
    AbstractState(const string & name);

private:
    string _name; // nom de l'état
};

#endif // ABSTRACTSTATE_H
