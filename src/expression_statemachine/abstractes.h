#ifndef ABSTRACTES_H
#define ABSTRACTES_H

#include "expressionstatemachine.h"
#include "src/interfaces/abstractstate.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class AbstractES : public AbstractState
{
public:
    ~AbstractES(){}

    /**
     * @brief Réalise la transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual int Transition(ExpressionStateMachine & machine, Symbol symbol);

protected:
    AbstractES(const string & name);

};

#endif // ABSTRACTES_H
