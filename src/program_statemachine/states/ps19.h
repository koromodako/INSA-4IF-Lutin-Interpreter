#ifndef PS19_H
#define PS19_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * num->PS20
*/
class PS19 : public AbstractState
{
public:
    ~PS19(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS19();
};

#endif // PS19_H
