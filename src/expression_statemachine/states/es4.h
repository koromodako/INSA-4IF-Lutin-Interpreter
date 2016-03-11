#ifndef ES4_H
#define ES4_H


#include "src/expression_statemachine/abstractes.h"

/**
 * @brief Etat définissant le comportement par defaut pour les Transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class ES4 : public AbstractES
{
public:
    ES4();
    ~ES4(){}

    /**
     * @brief Réalise la Transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual int Transition(ExpressionStateMachine & machine, Symbol symbol);

};

#endif // ES4_H
