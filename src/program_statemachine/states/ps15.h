#ifndef PS15_H
#define PS15_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS15 : public AbstractPS
{
public:
    ~PS15(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS15();
};

#endif // PS15_H
