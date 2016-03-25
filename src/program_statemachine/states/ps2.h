#ifndef PS2_H
#define PS2_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * lire, ecrire, id, $ -> R10
 * LI->PS3
 */
class PS2 : public AbstractState
{
public:
    ~PS2(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);

    PS2();
};

#endif // PS2_H
