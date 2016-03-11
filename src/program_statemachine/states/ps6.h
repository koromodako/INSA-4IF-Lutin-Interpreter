#ifndef PS6_H
#define PS6_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * id->PS7
*/
class PS6 : public AbstractState
{
public:
    ~PS6(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);

    PS6();
};

#endif // PS6_H
