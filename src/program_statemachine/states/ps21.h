#ifndef PS21_H
#define PS21_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * ,, ;->R6
 * LD->PS22
*/
class PS21 : public AbstractPS
{
public:
    ~PS21(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS21();
};

#endif // PS21_H
