#include "ps9.h"

#include "ps10.h"

AbstractState::TransitionResult PS9::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_AFFECT:///< ':='
        machine.PileUp(symbol, new PS10());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::ErrorType::SYNTAX_ERROR, symbol);
        break;
    }
    return ret;
}

PS9::PS9() :
    AbstractState("PS09")
{

}
