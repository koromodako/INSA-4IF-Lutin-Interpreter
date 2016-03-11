#include "ps25.h"
#include "ps26.h"

AbstractState::TransitionResult PS25::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_NUM:///< nombre '\d+'
            machine.GetDataMap().SetDataValue(symbol.buf);
            machine.GetDataMap().EndData();
            machine.PileUp(symbol, new PS26());
            ret = AbstractState::PILED_UP;
            break;
        default:
            machine.Unexpected(symbol);
            ret = AbstractState::UNEXPECTED;
            break;
    }
    return ret;
}

PS25::PS25() :
    AbstractState("PS25")
{

}
