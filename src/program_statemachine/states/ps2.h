#ifndef PS2_H
#define PS2_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS2 : public AbstractPS
{
public:
    ~PS2(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS2();
};

#endif // PS2_H
