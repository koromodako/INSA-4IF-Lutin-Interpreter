#include "ps24.h"
#include "ps25.h"

AbstractState::TransitionResult PS24::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_EQ:///< '='
            machine.PileUp(symbol, new PS25());
            ret = AbstractState::PILED_UP;
            break;
        default:
            machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_EQ);
            break;
    }
    return ret;
}

PS24::PS24() :
    AbstractState("PS24")
{

}
