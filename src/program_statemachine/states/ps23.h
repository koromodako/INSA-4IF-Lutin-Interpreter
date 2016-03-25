#ifndef PS23_H
#define PS23_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 *id->PS24
*/
class PS23 : public AbstractState
{
public:
    ~PS23(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS23();
};

#endif // PS23_H
