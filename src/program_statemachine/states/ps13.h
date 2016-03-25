#ifndef PS13_H
#define PS13_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * ,->PS14
 * ;->PS16
*/
class PS13 : public AbstractState
{
public:
    ~PS13(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS13();
};

#endif // PS13_H
