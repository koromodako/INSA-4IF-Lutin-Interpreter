#include "ps27.h"
#include "../rules.h"

AbstractState::TransitionResult PS27::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_CONST:///< mot-clé 'const'
            machine.Reduce(SYM_D, RULE_7);
            ret = AbstractState::REDUCED;
            break;
        case S_VAR:///< mot-clé 'var'
            machine.Reduce(SYM_D, RULE_7);
            ret = AbstractState::REDUCED;
            break;
        case S_READ:///< 'lire'
            machine.Reduce(SYM_D, RULE_7);
            ret = AbstractState::REDUCED;
            break;
        case S_WRITE:///< 'ecrire'
            machine.Reduce(SYM_D, RULE_7);
            ret = AbstractState::REDUCED;
            break;
        case S_ID:///< identifiant '\w[\w\d]*'
            machine.Reduce(SYM_D, RULE_7);
            ret = AbstractState::REDUCED;
            break;
        case S_EOF:///< $
            machine.Reduce(SYM_D, RULE_7);
            ret = AbstractState::REDUCED;
            break;
        default:
            machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, "Illegal instruction");
            break;
    }
    return ret;

}

PS27::PS27() :
    AbstractState("PS27")
{

}
