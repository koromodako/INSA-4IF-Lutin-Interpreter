#ifndef PS4_H
#define PS4_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * lire, écrire, id, $->R10
 */
class PS4 : public AbstractState
{
public:
    ~PS4(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);

    PS4();
};

#endif // PS4_H
