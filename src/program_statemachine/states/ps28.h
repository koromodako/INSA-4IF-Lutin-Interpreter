#ifndef PS28_H
#define PS28_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief
 *lire, ecrire, id, $->R9
*/
class PS28 : public AbstractState
{
public:
    ~PS28(){}

    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);
    PS28();
};

#endif // PS28_H
