#include "ps26.h"
#include "../rules.h"

AbstractState::TransitionResult PS26::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_V:///< ','
            machine.Reduce(SYM_LC, RULE_8);
            ret = AbstractState::REDUCED;
            break;
        case S_PV:///< ';'
            machine.Reduce(SYM_LC, RULE_8);
            ret = AbstractState::REDUCED;
            break;
        default:
            machine.Unexpected(AbstractStateMachine::ErrorType::SYNTAX_ERROR, symbol);
            break;
    }
    return ret;
}

PS26::PS26() :
    AbstractState("PS26")
{

}
