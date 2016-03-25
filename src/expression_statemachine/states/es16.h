#ifndef ES16_H
#define ES16_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief Etat définissant le comportement par défaut pour les transitions des états de
 *      la machine à états qui analyse les expressions arithmétiques.
 */
class ES16 : public AbstractState
{
public:
    ES16();
    ~ES16(){}

    /**
     * @brief Réalise la transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);

};

#endif // ES16_H
