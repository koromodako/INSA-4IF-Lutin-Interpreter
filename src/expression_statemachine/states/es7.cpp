#include "es7.h"
#include "../rules.h"

AbstractState::TransitionResult ES7::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EOF:
        machine.Reduce(SYM_T, RULE_5);
        ret = AbstractState::REDUCED;
        break;
    case S_PF:
        machine.Reduce(SYM_T, RULE_5);
        ret = AbstractState::REDUCED;
        break;
    case S_PLUS:
        machine.Reduce(SYM_T, RULE_5);
        ret = AbstractState::REDUCED;
        break;
    case S_MINUS:
        machine.Reduce(SYM_T, RULE_5);
        ret = AbstractState::REDUCED;
        break;
    case S_MULT:
        machine.Reduce(SYM_T, RULE_5);
        ret = AbstractState::REDUCED;
        break;
    case S_DIV:
        machine.Reduce(SYM_T, RULE_5);
        ret = AbstractState::REDUCED;
        break;
    case S_PV:
        machine.Reduce(SYM_T, RULE_5);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR,S_PV);
        break;
    }
    return ret;
}

ES7::ES7() :
    AbstractState("ES07")
{

}
