#include "ps0.h"

#include "ps1.h"
#include "../rules.h"

AbstractState::TransitionResult PS0::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_CONST:///< mot-clé 'const'
        machine.Reduce(RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_VAR:///< mot-clé 'var'
        machine.Reduce(RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_READ:///< 'lire'
        machine.Reduce(RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_LD:///< liste de déclarations
        machine.PileUp(symbol, new PS1());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;

}

PS0::PS0() :
    AbstractState("PS0")
{

}
