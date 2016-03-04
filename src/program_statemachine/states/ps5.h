#ifndef PS5_H
#define PS5_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS5 : public AbstractPS
{
public:
    ~PS5(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS5();
};

#endif // PS5_H
