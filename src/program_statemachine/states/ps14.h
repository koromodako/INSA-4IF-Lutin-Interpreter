#ifndef PS14_H
#define PS14_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * id->PS15
*/
class PS14 : public AbstractPS
{
public:
    ~PS14(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS14();
};

#endif // PS14_H
