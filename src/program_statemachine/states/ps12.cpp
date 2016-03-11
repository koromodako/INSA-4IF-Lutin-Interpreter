#include "ps12.h"
#include "ps13.h"
#include "../rules.h"

AbstractState::TransitionResult PS12::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_V:///< ','
        machine.Reduce(RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_PV:///< ';'
        machine.Reduce(RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_LV:
        machine.PileUp(symbol, new PS13());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;

}

PS12::PS12() :
    AbstractState("PS12")
{

}
