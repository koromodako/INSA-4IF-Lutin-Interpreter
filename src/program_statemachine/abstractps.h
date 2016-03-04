#ifndef ABSTRACTPS_H
#define ABSTRACTPS_H

#include "programstatemachine.h"
#include "src/interfaces/abstractstate.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class AbstractPS : public AbstractState
{
public:
    ~AbstractPS(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    AbstractPS(const string & name);
};

#endif // ABSTRACTPS_H
