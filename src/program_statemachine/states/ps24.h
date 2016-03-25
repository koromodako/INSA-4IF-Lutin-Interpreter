#ifndef PS24_H
#define PS24_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * num->PS25
*/
class PS24 : public AbstractState
{
public:
    ~PS24(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS24();
};

#endif // PS24_H
