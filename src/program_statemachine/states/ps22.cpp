#include "ps22.h"
#include "ps23.h"
#include "ps27.h"

AbstractState::TransitionResult PS22::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_V:///< ','
            machine.PileUp(symbol, new PS23());
            ret = AbstractState::PILED_UP;
            break;
        case S_PV:///< ';'
            machine.PileUp(symbol, new PS27());
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

PS22::PS22() :
    AbstractState("PS22")
{

}
