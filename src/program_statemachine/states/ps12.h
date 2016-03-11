#ifndef PS12_H
#define PS12_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * ,, ;->R2
 * LV->PS13
*/
class PS12 : public AbstractState
{
public:
    ~PS12(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS12();
};

#endif // PS12_H
