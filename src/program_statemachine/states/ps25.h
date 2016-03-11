#ifndef PS25_H
#define PS25_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * var->PS26
*/
class PS25 : public AbstractState
{
public:
    ~PS25(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS25();
};

#endif // PS25_H
