#ifndef ES0_H
#define ES0_H


#include "src/expression_statemachine/abstractes.h"

/**
 * @brief Etat définissant le comportement par defaut pour les Transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class ES0 : public AbstractES
{
public:
    ES0();
    ~ES0(){}

    /**
     * @brief Réalise la Transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual int Transition(ExpressionStateMachine & machine, Symbol symbol);

};

#endif // ES0_H
