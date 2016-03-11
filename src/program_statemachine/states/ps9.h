#ifndef PS9_H
#define PS9_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * := ->PS10
*/
class PS9 : public AbstractPS
{
public:
    ~PS9(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS9();
};

#endif // PS9_H
