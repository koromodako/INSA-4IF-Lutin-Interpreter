#include "ps25.h"
#include "ps26.h"

AbstractState::TransitionResult PS25::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_NUM:///< nombre '\d+'
            // on affecte la variable en cours d'ajout ce qui a pour effet de terminer
            // la transaction d'insertion (initiée dans l'état 23) au niveau de DataMap
            if(machine.GetDataMap().SetDataValue(symbol.buf))
            {
                machine.PileUp(symbol, new PS26());
                ret = AbstractState::PILED_UP;
            }
            else
            {
                machine.Unexpected(AbstractStateMachine::WARNING,machine.GetDataMap().GetLastError());
            }
            break;
        default:
            if(machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_NUM))
            {   Transition(machine, SYM_NUM);
            }
            break;
    }
    return ret;
}

PS25::PS25() :
    AbstractState("PS25")
{

}
