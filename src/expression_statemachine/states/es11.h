#ifndef ES11_H
#define ES11_H


#include "src/interfaces/abstractstate.h"

/**
 * @brief Etat définissant le comportement par défaut pour les transitions des états de
 *      la machine à états qui analyse les expressions arithmétiques.
 */
class ES11 : public AbstractState
{
public:
    ES11();
    ~ES11(){}

    /**
     * @brief Réalise la transition depuis un état vers un autre état
     * @param machine
     * @param symbol
     * @return
     */
    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol);

};

#endif // ES11_H
