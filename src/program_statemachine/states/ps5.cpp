#include "ps5.h"

#include "ps29.h"
AbstractState::TransitionResult PS5::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EXP:///< expression arithmetique
        machine.GetInstructionList().StartPrint();
        machine.PileUp(symbol, new PS29());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;
}

PS5::PS5() :
    AbstractState("PS05")
{

}
