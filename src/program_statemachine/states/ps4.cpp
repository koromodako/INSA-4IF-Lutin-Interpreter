#include "ps4.h"
#include "../rules.h"

AbstractState::TransitionResult PS4::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {

    case S_READ:///< 'lire'
        machine.Reduce(SYM_LI, RULE_10);
        ret = AbstractState::REDUCED;
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(SYM_LI, RULE_10);
        ret = AbstractState::REDUCED;
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(SYM_LI, RULE_10);
        ret = AbstractState::REDUCED;
        break;
    case S_EOF:///< $
        machine.Reduce(SYM_LI, RULE_10);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;
}

PS4::PS4() :
    AbstractState("PS04")
{

}
