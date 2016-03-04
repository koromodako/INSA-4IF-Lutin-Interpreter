#ifndef PS18_H
#define PS18_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS18 : public AbstractPS
{
public:
    ~PS18(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS18();
};

#endif // PS18_H
