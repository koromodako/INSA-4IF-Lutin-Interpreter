#ifndef ES13_H
#define ES13_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief Etat définissant le comportement par défaut pour les transitions des états de
 *      la machine à états qui analyse les expressions arithmétiques.
 */
class ES13 : public AbstractState
{
public:
    ES13();
    ~ES13(){}

    /**
     * @brief Réalise la transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);

};

#endif // ES13_H
