#include "ps23.h"
#include "ps24.h"

AbstractState::TransitionResult PS23::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_ID:///< identifiant '\w[\w\d]*'
            machine.GetDataMap().StartConst(symbol.buf);
            machine.PileUp(symbol, new PS24());
            ret = AbstractState::PILED_UP;
            break;
        default:
            machine.Unexpected(symbol);
            ret = AbstractState::UNEXPECTED;
            break;
    }
    return ret;

}

PS23::PS23() :
    AbstractState("PS23")
{

}
