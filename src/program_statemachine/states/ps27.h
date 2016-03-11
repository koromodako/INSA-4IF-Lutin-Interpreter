#ifndef PS27_H
#define PS27_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * const, var, lire, ecrire, id, $->R5
*/
class PS27 : public AbstractState
{
public:
    ~PS27(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS27();
};

#endif // PS27_H
