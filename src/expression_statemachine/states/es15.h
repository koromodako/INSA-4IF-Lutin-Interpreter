#ifndef ES15_H
#define ES15_H


#include "src/expression_statemachine/abstractes.h"

/**
 * @brief Etat définissant le comportement par defaut pour les Transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class ES15 : public AbstractES
{
public:
    ES15();
    ~ES15(){}

    /**
     * @brief Réalise la Transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual int Transition(ExpressionStateMachine & machine, Symbol symbol);

};

#endif // ES15_H
