#ifndef PS26_H
#define PS26_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS26 : public AbstractPS
{
public:
    ~PS26(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS26();
};

#endif // PS26_H
