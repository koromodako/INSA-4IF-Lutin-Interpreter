#ifndef PS1_H
#define PS1_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * const->PS18
 * var->PS11
 * lire-> PS6
 * ecrire->PS5
 * id->PS3
 * D->PS17
 * I->PS2
*/
class PS1 : public AbstractPS
{
public:
    ~PS1(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS1();
};

#endif // PS1_H
