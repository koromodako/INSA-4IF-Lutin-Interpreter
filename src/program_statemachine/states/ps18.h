#ifndef PS18_H
#define PS18_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 * id->PS19
*/
class PS18 : public AbstractState
{
public:
    ~PS18(){}
    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);
    PS18();
};

#endif // PS18_H
