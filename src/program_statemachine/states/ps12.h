#ifndef PS12_H
#define PS12_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS12 : public AbstractPS
{
public:
    ~PS12(){}

    virtual int transition(ProgramStateMachine & machine, ProgramStateMachine::Symbol symbol);

protected:
    PS12();
};

#endif // PS12_H
