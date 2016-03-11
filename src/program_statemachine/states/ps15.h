#ifndef PS15_H
#define PS15_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ,, ;->R2
*/
class PS15 : public AbstractPS
{
public:
    ~PS15(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);
    PS15();
};

#endif // PS15_H
