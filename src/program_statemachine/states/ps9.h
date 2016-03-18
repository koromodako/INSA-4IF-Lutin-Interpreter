#ifndef PS9_H
#define PS9_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * := ->PS10
*/
class PS9 : public AbstractState
{
public:
    ~PS9(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);

    PS9();
};

#endif // PS9_H
