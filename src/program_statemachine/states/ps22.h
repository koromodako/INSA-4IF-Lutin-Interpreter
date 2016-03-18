#ifndef PS22_H
#define PS22_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * ,->PS23
 * ;->PS27
*/
class PS22 : public AbstractState
{
public:
    ~PS22(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS22();
};

#endif // PS22_H
