#ifndef PS7_H
#define PS7_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ;->PS8
*/
class PS7 : public AbstractPS
{
public:
    ~PS7(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS7();
};

#endif // PS7_H
