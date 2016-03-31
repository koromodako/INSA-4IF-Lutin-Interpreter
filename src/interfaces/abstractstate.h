#ifndef ABSTRACTSTATE_H
#define ABSTRACTSTATE_H

#include <string>
#include "../config.h"
#include "../types/types.h"
#include "abstractstatemachine.h"

using namespace std;
class AbstractStateMachine;
/**
 * @brief Cette classe abstraite représente un état quelconque d'une machine à états
 */
class AbstractState
{
public:
    /**
     * @brief Cette énumération définit les différents résultats possibles suite à une transition
     */
    enum TransitionResult
    {
        UNEXPECTED, ///<    Erreur
        REDUCED,    ///<    Réduction d'une règle
        PILED_UP,   ///<    Empilement d'un nouvel état
        ACCEPT      ///<    Fin de l'exécution
    };
    virtual ~AbstractState(){}
    /**
     * @brief Réalise la transition de l'état vers un autre état
     * @param machine
     *      Machine à états contenant l'état courant
     * @param symbol
     *      Symbole suivant
     * @return
     */
    virtual TransitionResult Transition(AbstractStateMachine & machine, const Symbol & symbol) = 0;
    /**
     * @brief Retourne le nom de l'état courant
     * @return
     */
    inline const string & name() const { return _name; }

protected:
    // constructeur privé (classe abstraite)
    AbstractState(const string & name);

private:
    string _name; // nom de l'état
};

// ------------------ macros
#   define SYNTAX_ERROR_HANDLER(expectedSymbol) \
        machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, expectedSymbol);

#endif // ABSTRACTSTATE_H
