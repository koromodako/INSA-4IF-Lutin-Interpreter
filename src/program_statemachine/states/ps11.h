#ifndef PS11_H
#define PS11_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * id->PS12
*/
class PS11 : public AbstractPS
{
public:
    ~PS11(){}
    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);
    PS11();
};

#endif // PS11_H
