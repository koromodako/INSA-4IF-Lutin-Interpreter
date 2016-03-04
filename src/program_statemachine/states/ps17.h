#ifndef PS17_H
#define PS17_H


#include "src/program_statemachine/abstractps.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les scripts lutin.
 */
class PS17 : public AbstractPS
{
public:
    ~PS17(){}

    virtual int transition(ProgramStateMachine & machine, Symbol symbol);

protected:
    PS17();
};

#endif // PS17_H
