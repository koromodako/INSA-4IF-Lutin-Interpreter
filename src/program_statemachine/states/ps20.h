#ifndef PS20_H
#define PS20_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * num->PS21
*/
class PS20 : public AbstractState
{
public:
    ~PS20(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS20();
};

#endif // PS20_H
