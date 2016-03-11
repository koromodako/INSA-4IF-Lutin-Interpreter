#ifndef PS24_H
#define PS24_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * = ->PS25
*/
class PS24 : public AbstractPS
{
public:
    ~PS24(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS24();
};

#endif // PS24_H
