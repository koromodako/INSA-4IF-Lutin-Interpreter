#include "ps14.h"
#include "ps15.h"

AbstractState::TransitionResult PS14::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        // on ajoute la nouvelle variable
        machine.GetDataMap().AppendVar(symbol.buf);
        machine.PileUp(symbol, new PS15());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, symbol);
        break;
    }
    return ret;

}

PS14::PS14() :
    AbstractState("PS14")
{

}
