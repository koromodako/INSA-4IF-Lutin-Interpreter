#ifndef PS28_H
#define PS28_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 *lire, ecrire, id, $->R9
*/
class PS28 : public AbstractPS
{
public:
    ~PS28(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS28();
};

#endif // PS28_H
