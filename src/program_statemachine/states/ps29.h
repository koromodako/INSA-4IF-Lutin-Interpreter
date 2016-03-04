#ifndef PS29_H
#define PS29_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS29 : public AbstractPS
{
public:
    ~PS29(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS29();
};

#endif // PS29_H
