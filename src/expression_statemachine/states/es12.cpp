#include "es12.h"
#include "../rules.h"

AbstractState::TransitionResult ES12::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EOF:
        machine.Reduce(SYM_T, RULE_7);
        ret = AbstractState::REDUCED;
        break;
    case S_PF:
        machine.Reduce(SYM_T, RULE_7);
        ret = AbstractState::REDUCED;
        break;
    case S_PLUS:
        machine.Reduce(SYM_T, RULE_7);
        ret = AbstractState::REDUCED;
        break;
    case S_MINUS:
        machine.Reduce(SYM_T, RULE_7);
        ret = AbstractState::REDUCED;
        break;
    case S_MULT:
        machine.Reduce(SYM_T, RULE_7);
        ret = AbstractState::REDUCED;
        break;
    case S_DIV:
        machine.Reduce(SYM_T, RULE_7);
        ret = AbstractState::REDUCED;
        break;
    case S_PV:
        machine.Reduce(SYM_T, RULE_7);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;
}

ES12::ES12() :
    AbstractState("ES12")
{

}
