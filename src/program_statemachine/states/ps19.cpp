#include "ps19.h"
#include "ps20.h"

AbstractState::TransitionResult PS19::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EQ:///< nombre '\d+'
        machine.PileUp(symbol, new PS20());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_EQ);
        break;
    }
    return ret;
}

PS19::PS19() :
    AbstractState("PS19")
{

}
