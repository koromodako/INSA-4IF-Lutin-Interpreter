#ifndef PS3_H
#define PS3_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * lire->PS6
 * ecrire->PS5
 * id->PS9
 * $->R1+A
 * I->PS4
*/
class PS3 : public AbstractState
{
public:
    ~PS3(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS3();
};

#endif // PS3_H
