#ifndef ES12_H
#define ES12_H


#include "src/expression_statemachine/abstractes.h"

/**
 * @brief Etat définissant le comportement par defaut pour les Transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class ES12 : public AbstractES
{
public:
    ES12();
    ~ES12(){}

    /**
     * @brief Réalise la Transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual int Transition(ExpressionStateMachine & machine, Symbol symbol);

};

#endif // ES12_H
