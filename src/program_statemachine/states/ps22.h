#ifndef PS22_H
#define PS22_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ,->PS23
 * ;->PS27
*/
class PS22 : public AbstractPS
{
public:
    ~PS22(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS22();
};

#endif // PS22_H
