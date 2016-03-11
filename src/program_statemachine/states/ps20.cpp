#include "ps20.h"
#include "ps21.h"

AbstractState::TransitionResult PS20::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_NUM:///< nombre '\d+'
            machine.GetDataMap().SetDataValue(symbol.buf);
            machine.GetDataMap().EndData();
            machine.PileUp(symbol, new PS21());
            ret = AbstractState::PILED_UP;
            break;
        default:
            machine.Unexpected(symbol);
            break;
    }
    return ret;
}

PS20::PS20() :
    AbstractState("PS20")
{

}
