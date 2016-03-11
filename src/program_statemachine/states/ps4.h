#ifndef PS4_H
#define PS4_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * lire, écrire, id, $->R10
 */
class PS4 : public AbstractPS
{
public:
    ~PS4(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS4();
};

#endif // PS4_H
