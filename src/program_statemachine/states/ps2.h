#ifndef PS2_H
#define PS2_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * lire, ecrire, id, $ -> R10
 * LI->PS3
 */
class PS2 : public AbstractPS
{
public:
    ~PS2(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS2();
};

#endif // PS2_H
