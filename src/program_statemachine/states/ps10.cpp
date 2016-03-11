#include "ps10.h"
#include "ps28.h"

AbstractState::TransitionResult PS10::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EXP:///< expression arithmetique
        //machine.GetDataMap().SetDataValue(symbol.buf); autre automate
        machine.PileUp(symbol, new PS28());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;

}

PS10::PS10() :
    AbstractState("PS10")
{

}
