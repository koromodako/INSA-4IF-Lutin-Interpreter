#include "ps7.h"

#include "ps8.h"
AbstractState::TransitionResult PS7::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_PV:///< ';'
        machine.PileUp(symbol, new PS8());
        ret = AbstractState::PILED_UP;
        break;
    default:
        if(machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_PV))
        {   Transition(machine, SYM_PV);
        }
        break;
    }
    return ret;
}

PS7::PS7() :
    AbstractState("PS07")
{

}
