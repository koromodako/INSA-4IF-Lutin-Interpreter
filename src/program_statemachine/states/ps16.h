#ifndef PS16_H
#define PS16_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * const, var, lire, ecrire, id, $->R2
*/
class PS16 : public AbstractPS
{
public:
    ~PS16(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS16();
};

#endif // PS16_H
