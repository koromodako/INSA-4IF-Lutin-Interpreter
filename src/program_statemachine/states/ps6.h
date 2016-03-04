#ifndef PS6_H
#define PS6_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * id->PS7
*/
class PS6 : public AbstractPS
{
public:
    ~PS6(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS6();
};

#endif // PS6_H
