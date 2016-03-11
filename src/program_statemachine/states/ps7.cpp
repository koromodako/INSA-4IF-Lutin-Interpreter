#include "ps7.h"

#include "ps8.h"
AbstractState::TransitionResult PS7::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_PV:///< ';'
        machine.GetInstructionList().EndInstruction();
        machine.PileUp(symbol, new PS8());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;
}

PS7::PS7() :
    AbstractState("PS07")
{

}
