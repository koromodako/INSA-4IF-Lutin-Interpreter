#ifndef PS7_H
#define PS7_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * ;->PS8
*/
class PS7 : public AbstractState
{
public:
    ~PS7(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS7();
};

#endif // PS7_H
