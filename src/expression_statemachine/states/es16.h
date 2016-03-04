#ifndef ES16_H
#define ES16_H


#include "src/expression_statemachine/abstractes.h"

/**
 * @brief Etat définissant le comportement par defaut pour les transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class ES16 : public AbstractES
{
public:
    ~ES16(){}

    /**
     * @brief Réalise la transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual int transition(ExpressionStateMachine & machine, ExpressionStateMachine::Symbol symbol);

protected:
    ES16();

};

#endif // ES16_H
