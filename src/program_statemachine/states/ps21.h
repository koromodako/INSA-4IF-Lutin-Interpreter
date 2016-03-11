#ifndef PS21_H
#define PS21_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ,, ;->R9
 * LC->PS22
*/
class PS21 : public AbstractPS
{
public:
    ~PS21(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS21();
};

#endif // PS21_H
