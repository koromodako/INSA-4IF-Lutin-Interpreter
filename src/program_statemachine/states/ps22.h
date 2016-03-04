#ifndef PS22_H
#define PS22_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS22 : public AbstractPS
{
public:
    ~PS22(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS22();
};

#endif // PS22_H
