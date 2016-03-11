#include "ps16.h"
#include "../rules.h"
AbstractState::TransitionResult PS16::Transition(AbstractStateMachine &machine, Symbol symbol)
{

    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_CONST:///< mot-clé 'const'
        machine.Reduce(RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_VAR:///< mot-clé 'var'
        machine.Reduce(RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_READ:///< 'lire'
        machine.Reduce(RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_EOF:///< $
        machine.Reduce(RULE_6);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(symbol);
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;

}

PS16::PS16() :
    AbstractState("PS16")
{

}
