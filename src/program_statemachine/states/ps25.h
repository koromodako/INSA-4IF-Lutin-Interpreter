#ifndef PS25_H
#define PS25_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS25 : public AbstractPS
{
public:
    ~PS25(){}

    virtual int transition(ProgramStateMachine & machine, ProgramStateMachine::Symbol symbol);

protected:
    PS25();
};

#endif // PS25_H
