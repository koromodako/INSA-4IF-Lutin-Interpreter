#ifndef PS26_H
#define PS26_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ,, ;->R8
**/
class PS26 : public AbstractPS
{
public:
    ~PS26(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS26();
};

#endif // PS26_H
