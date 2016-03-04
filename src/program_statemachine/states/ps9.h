#ifndef PS9_H
#define PS9_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS9 : public AbstractPS
{
public:
    ~PS9(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS9();
};

#endif // PS9_H
