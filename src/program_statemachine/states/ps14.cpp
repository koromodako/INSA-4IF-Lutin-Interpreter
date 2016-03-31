#include "ps14.h"
#include "ps15.h"

AbstractState::TransitionResult PS14::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        // on ajoute la nouvelle variable
        if(!machine.GetDataMap().AppendVar(symbol.buf))
            machine.Unexpected(AbstractStateMachine::WARNING,machine.GetDataMap().GetLastError());

        machine.PileUp(symbol, new PS15());
        ret = AbstractState::PILED_UP;
        break;
    default:
        SYNTAX_ERROR_HANDLER(SYM_ID)
        break;
    }
    return ret;

}

PS14::PS14() :
    AbstractState("PS14")
{

}
