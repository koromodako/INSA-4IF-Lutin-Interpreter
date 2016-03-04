#ifndef ES17_H
#define ES17_H


#include "src/expression_statemachine/abstractes.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class ES17 : public AbstractES
{
public:
    ~ES17(){}

    /**
     * @brief Réalise la transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual int transition(ExpressionStateMachine & machine, ExpressionStateMachine::Symbol symbol);

protected:
    ES17();

};

#endif // ES17_H
