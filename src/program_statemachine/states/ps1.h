#ifndef PS1_H
#define PS1_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * const->PS18
 * var->PS11
 * lire-> PS6
 * ecrire->PS5
 * id->PS3
 * D->PS17
 * I->PS2
*/
class PS1 : public AbstractState
{
public:
    ~PS1(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS1();
};

#endif // PS1_H
