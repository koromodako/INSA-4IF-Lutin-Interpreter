#ifndef PS16_H
#define PS16_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS16 : public AbstractPS
{
public:
    ~PS16(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS16();
};

#endif // PS16_H
