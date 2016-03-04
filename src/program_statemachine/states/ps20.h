#ifndef PS20_H
#define PS20_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS20 : public AbstractPS
{
public:
    ~PS20(){}

    virtual int transition(ProgramStateMachine & machine, ProgramStateMachine::Symbol symbol);

protected:
    PS20();
};

#endif // PS20_H
