#ifndef PS29_H
#define PS29_H


#include "src/program_statemachine/abstractps.h"
/**
 * @brief
 *lire, ecrire, id, $->R10
*/
class PS29 : public AbstractPS
{
public:
    ~PS29(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);
    PS29();
};

#endif // PS29_H
