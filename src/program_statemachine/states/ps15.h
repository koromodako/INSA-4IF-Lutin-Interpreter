#ifndef PS15_H
#define PS15_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * ,, ;->R3
*/
class PS15 : public AbstractState
{
public:
    ~PS15(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS15();
};

#endif // PS15_H
