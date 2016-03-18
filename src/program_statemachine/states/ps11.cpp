#include "ps11.h"
#include "ps12.h"

AbstractState::TransitionResult PS11::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:///< 'id'
        // on ajoute la nouvelle variable
        machine.GetDataMap().AppendVar(symbol.buf);
        machine.PileUp(symbol, new PS12());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, symbol);
        break;
    }
    return ret;

}

PS11::PS11() :
    AbstractState("PS11")
{

}
