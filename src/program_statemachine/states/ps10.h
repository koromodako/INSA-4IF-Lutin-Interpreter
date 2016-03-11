#ifndef PS10_H
#define PS10_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * exp->PS28
*/
class PS10 : public AbstractState
{
public:
    ~PS10(){}
    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS10();
};

#endif // PS10_H
