#ifndef PS8_H
#define PS8_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * lire, ecrire, id, $ -> R8
*/
class PS8 : public AbstractPS
{
public:
    ~PS8(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);

    PS8();
};

#endif // PS8_H
