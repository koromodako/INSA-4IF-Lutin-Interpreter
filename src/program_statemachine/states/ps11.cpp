#include "ps11.h"
#include "ps12.h"

AbstractState::TransitionResult PS11::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_WRITE:///< 'ecrire'
        machine.PileUp(symbol, new PS12());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);ret = AbstractState::UNEXPECTED;
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;
}

PS11::PS11() :
    AbstractState("PS11")
{

}
