#ifndef PS10_H
#define PS10_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * exp->PS28
*/
class PS10 : public AbstractPS
{
public:
    ~PS10(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);
    PS10();
};

#endif // PS10_H
