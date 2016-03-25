#ifndef PS5_H
#define PS5_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * exp->PS29
*/
class PS5 : public AbstractState
{
public:
    ~PS5(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);

    PS5();
};

#endif // PS5_H
