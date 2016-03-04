#ifndef PS17_H
#define PS17_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * const, var, lire, ecrire, id->R4
*/
class PS17 : public AbstractPS
{
public:
    ~PS17(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS17();
};

#endif // PS17_H
