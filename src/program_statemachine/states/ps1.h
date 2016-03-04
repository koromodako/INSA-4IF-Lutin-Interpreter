#ifndef PS1_H
#define PS1_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS1 : public AbstractPS
{
public:
    ~PS1(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS1();
};

#endif // PS1_H
