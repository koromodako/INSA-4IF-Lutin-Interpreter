#ifndef PS5_H
#define PS5_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * exp->PS29
*/
class PS5 : public AbstractPS
{
public:
    ~PS5(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS5();
};

#endif // PS5_H
