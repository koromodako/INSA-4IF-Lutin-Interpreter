#include "es10.h"
#include "../rules.h"

AbstractState::TransitionResult ES10::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EOF:
        machine.Reduce(RULE_9);
        ret = AbstractState::REDUCED;
        break;
    case S_PF:
        machine.Reduce(RULE_9);
        ret = AbstractState::REDUCED;
        break;
    case S_PLUS:
        machine.Reduce(RULE_9);
        ret = AbstractState::REDUCED;
        break;
    case S_MINUS:
        machine.Reduce(RULE_9);
        ret = AbstractState::REDUCED;
        break;
    case S_MULT:
        machine.Reduce(RULE_9);
        ret = AbstractState::REDUCED;
        break;
    case S_DIV:
        machine.Reduce(RULE_9);
        ret = AbstractState::REDUCED;
        break;
    case S_PV:
        machine.Reduce(RULE_9);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(symbol);ret = AbstractState::UNEXPECTED;
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;
}

ES10::ES10() :
    AbstractState("ES10")
{

}
