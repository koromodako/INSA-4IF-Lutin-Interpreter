#ifndef PS26_H
#define PS26_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * ,, ;->R6
**/
class PS26 : public AbstractState
{
public:
    ~PS26(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS26();
};

#endif // PS26_H
