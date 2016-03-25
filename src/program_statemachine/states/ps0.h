#ifndef PS0_H
#define PS0_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * const, var, lire, ecrire, id -> R3
 * LD->PS1
 */
class PS0 : public AbstractState
{
public:
    ~PS0(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS0();
};

#endif // PS0_H
