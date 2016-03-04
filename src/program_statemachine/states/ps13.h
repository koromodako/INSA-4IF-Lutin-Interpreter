#ifndef PS13_H
#define PS13_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS13 : public AbstractPS
{
public:
    ~PS13(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS13();
};

#endif // PS13_H
