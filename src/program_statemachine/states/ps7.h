#ifndef PS7_H
#define PS7_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS7 : public AbstractPS
{
public:
    ~PS7(){}

    virtual int transition(ProgramStateMachine & machine, ProgramStateMachine::Symbol symbol);

protected:
    PS7();
};

#endif // PS7_H
