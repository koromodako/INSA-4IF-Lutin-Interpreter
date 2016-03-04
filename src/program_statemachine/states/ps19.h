#ifndef PS19_H
#define PS19_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS19 : public AbstractPS
{
public:
    ~PS19(){}

    virtual int transition(ProgramStateMachine & machine, ProgramStateMachine::Symbol symbol);

protected:
    PS19();
};

#endif // PS19_H
