#ifndef ES12_H
#define ES12_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief Etat définissant le comportement par defaut pour les Transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class ES12 : public AbstractState
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
    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);

};

#endif // ES12_H
