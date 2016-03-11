#include "ps19.h"
#include "ps20.h"

AbstractState::TransitionResult PS19::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_NUM:///< nombre '\d+'
        machine.PileUp(symbol, new PS20());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;
}

PS19::PS19() :
    AbstractState("PS19")
{

}
