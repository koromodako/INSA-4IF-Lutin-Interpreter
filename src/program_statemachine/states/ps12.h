#ifndef PS12_H
#define PS12_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ,, ;->R3
 * LV->PS13
*/
class PS12 : public AbstractPS
{
public:
    ~PS12(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);
    PS12();
};

#endif // PS12_H
