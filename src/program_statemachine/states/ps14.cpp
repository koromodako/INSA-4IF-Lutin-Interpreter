#include "ps14.h"
#include "ps15.h"

AbstractState::TransitionResult PS14::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        // on ajoute la nouvelle variable
        if(machine.GetDataMap().AppendVar(symbol.buf))
        {
            machine.PileUp(symbol, new PS15());
            ret = AbstractState::PILED_UP;
        }
        else
        {
            machine.Unexpected(AbstractStateMachine::WARNING,machine.GetDataMap().GetLastError());
        }
        break;
    default:
        if(machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_ID))
        {   Transition(machine, SYM_ID);
        }
        break;
    }
    return ret;

}

PS14::PS14() :
    AbstractState("PS14")
{

}
