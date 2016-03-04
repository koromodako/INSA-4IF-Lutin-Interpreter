#ifndef PS19_H
#define PS19_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * num->PS20
*/
class PS19 : public AbstractPS
{
public:
    ~PS19(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS19();
};

#endif // PS19_H
