#ifndef PS21_H
#define PS21_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * ,, ;->R6
 * LD->PS22
*/
class PS21 : public AbstractState
{
public:
    ~PS21(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS21();
};

#endif // PS21_H
