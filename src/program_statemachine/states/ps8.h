#ifndef PS8_H
#define PS8_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * lire, ecrire, id, $ -> R8
*/
class PS8 : public AbstractState
{
public:
    ~PS8(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);

    PS8();
};

#endif // PS8_H
