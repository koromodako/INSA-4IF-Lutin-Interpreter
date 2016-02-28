#ifndef ES6_H
#define ES6_H


#include "src/expression_statemachine/abstractes.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class ES6 : public AbstractES
{
public:
    ~ES6(){}

    /**
     * @brief Réalise la transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual int transition(ExpressionStateMachine & machine, ExpressionStateMachine::Symbol symbol);

protected:
    ES6();

};

#endif // ES6_H
