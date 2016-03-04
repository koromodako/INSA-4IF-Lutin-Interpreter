#ifndef PS0_H
#define PS0_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS0 : public AbstractPS
{
public:
    ~PS0(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS0();
};

#endif // PS0_H
