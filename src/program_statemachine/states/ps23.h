#ifndef PS23_H
#define PS23_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 *id->PS24
*/
class PS23 : public AbstractPS
{
public:
    ~PS23(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS23();
};

#endif // PS23_H
