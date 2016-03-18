#ifndef PS16_H
#define PS16_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * const, var, lire, ecrire, id, $->R2
*/
class PS16 : public AbstractState
{
public:
    ~PS16(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS16();
};

#endif // PS16_H
