#ifndef PS17_H
#define PS17_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * const, var, lire, ecrire, id->R4
*/
class PS17 : public AbstractState
{
public:
    ~PS17(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS17();
};

#endif // PS17_H
