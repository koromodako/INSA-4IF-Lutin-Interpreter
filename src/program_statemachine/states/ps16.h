#ifndef PS16_H
#define PS16_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * const, var, lire, ecrire, id, $->R6
*/
class PS16 : public AbstractPS
{
public:
    ~PS16(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);
    PS16();
};

#endif // PS16_H
