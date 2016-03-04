#ifndef PS12_H
#define PS12_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ,, ;->R2
 * LV->PS13
*/
class PS12 : public AbstractPS
{
public:
    ~PS12(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS12();
};

#endif // PS12_H
