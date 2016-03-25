#ifndef PS14_H
#define PS14_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * id->PS15
*/
class PS14 : public AbstractState
{
public:
    ~PS14(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS14();
};

#endif // PS14_H
