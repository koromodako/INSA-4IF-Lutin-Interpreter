#include "ps17.h"
#include "../rules.h"

AbstractState::TransitionResult PS17::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_CONST:///< mot-clé 'const'
        machine.Reduce(SYM_LD, RULE_4);
        ret = AbstractState::REDUCED;
        break;
    case S_VAR:///< mot-clé 'var'
        machine.Reduce(SYM_LD, RULE_4);
        ret = AbstractState::REDUCED;
        break;
    case S_READ:///< 'lire'
        machine.Reduce(SYM_LD, RULE_4);
        ret = AbstractState::REDUCED;
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(SYM_LD, RULE_4);
        ret = AbstractState::REDUCED;
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(SYM_LD, RULE_4);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::ERROR, "Illegal instruction");
        break;
    }
    return ret;

}

PS17::PS17() :
    AbstractState("PS17")
{

}
