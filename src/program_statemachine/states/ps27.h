#ifndef PS27_H
#define PS27_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * const, var, lire, ecrire, id, $->R7
*/
class PS27 : public AbstractPS
{
public:
    ~PS27(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS27();
};

#endif // PS27_H
