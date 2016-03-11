#ifndef PS0_H
#define PS0_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * const, var, lire, ecrire, id -> R3
 * LD->PS1
 */
class PS0 : public AbstractPS
{
public:
    ~PS0(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS0();
};

#endif // PS0_H
