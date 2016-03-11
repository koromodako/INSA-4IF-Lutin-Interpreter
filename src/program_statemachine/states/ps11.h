#ifndef PS11_H
#define PS11_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * id->PS12
*/
class PS11 : public AbstractState
{
public:
    ~PS11(){}
    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS11();
};

#endif // PS11_H
