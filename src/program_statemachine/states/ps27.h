#ifndef PS27_H
#define PS27_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * const, var, lire, ecrire, id, $->R5
*/
class PS27 : public AbstractPS
{
public:
    ~PS27(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS27();
};

#endif // PS27_H
