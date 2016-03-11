#include "ps6.h"

#include "ps7.h"

AbstractState::TransitionResult PS6::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.GetInstructionList().AppendRead(symbol.buf);
        machine.PileUp(symbol, new PS7());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        ret = AbstractState::UNEXPECTED;
        break;
    }
    return ret;
}

PS6::PS6() :
    AbstractState("PS6")
{

}
