#ifndef PS3_H
#define PS3_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief
 * lire->PS6
 * ecrire->PS5
 * id->PS9
 * $->R1+A
 * I->PS4
*/
class PS3 : public AbstractPS
{
public:
    ~PS3(){}

    virtual int Transition(ProgramStateMachine & machine, Symbol symbol);
    PS3();
};

#endif // PS3_H
