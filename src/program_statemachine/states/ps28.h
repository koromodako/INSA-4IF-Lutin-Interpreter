#ifndef PS28_H
#define PS28_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 *lire, ecrire, id, $->R12
*/
class PS28 : public AbstractPS
{
public:
    ~PS28(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS28();
};

#endif // PS28_H
