#include "ps13.h"
#include "ps14.h"
#include "ps16.h"

AbstractState::TransitionResult PS13::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_V:///< ','
        machine.PileUp(symbol, new PS14());
        ret = AbstractState::PILED_UP;
        break;
    case S_PV:///< ';'
        machine.PileUp(symbol, new PS16());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_PV);
        break;
    }
    return ret;

}

PS13::PS13() :
    AbstractState("PS13")
{

}
