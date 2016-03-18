#ifndef ES4_H
#define ES4_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief Etat définissant le comportement par defaut pour les Transitions des états de
 *      la machine à état qui analyse les expressions arithmétiques.
 */
class ES4 : public AbstractState
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
    virtual TransitionResult Transition(AbstractStateMachine & machine, Symbol symbol);

};

#endif // ES4_H
