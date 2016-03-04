#ifndef PS14_H
#define PS14_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS14 : public AbstractPS
{
public:
    ~PS14(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS14();
};

#endif // PS14_H
