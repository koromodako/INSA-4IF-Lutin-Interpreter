#include "ps18.h"
#include "ps19.h"

AbstractState::TransitionResult PS18::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.GetDataMap().StartConst(symbol.buf);
        machine.PileUp(symbol, new PS19());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;
}

PS18::PS18() :
    AbstractState("PS18")
{

}
