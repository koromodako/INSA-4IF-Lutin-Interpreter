#ifndef PS25_H
#define PS25_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * num->PS26
*/
class PS25 : public AbstractPS
{
public:
    ~PS25(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS25();
};

#endif // PS25_H
