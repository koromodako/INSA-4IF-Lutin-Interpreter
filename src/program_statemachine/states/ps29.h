#ifndef PS29_H
#define PS29_H


#include "src/interfaces/abstractstate.h"
/**
 * @brief
 *lire, ecrire, id, $->R10
*/
class PS29 : public AbstractState
{
public:
    ~PS29(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS29();
};

#endif // PS29_H
