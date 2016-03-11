#ifndef PS13_H
#define PS13_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ,->PS14
 * ;->PS16
*/
class PS13 : public AbstractPS
{
public:
    ~PS13(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);
    PS13();
};

#endif // PS13_H
