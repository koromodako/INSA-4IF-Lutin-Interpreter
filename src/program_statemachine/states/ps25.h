#ifndef PS25_H
#define PS25_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * var->PS26
*/
class PS25 : public AbstractPS
{
public:
    ~PS25(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS25();
};

#endif // PS25_H
