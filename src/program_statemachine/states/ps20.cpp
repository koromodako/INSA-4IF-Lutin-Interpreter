#include "ps20.h"
#include "ps21.h"

AbstractState::TransitionResult PS20::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_NUM:///< nombre '\d+'
            // on affecte la variable en cours d'ajout ce qui a pour effet de terminer
            // la transaction d'insertion (initiée dans l'état 18) au niveau de DataMap
            if(machine.GetDataMap().SetDataValue(symbol.buf))
            {
                machine.PileUp(symbol, new PS21());
                ret = AbstractState::PILED_UP;
            }
            else
            {
                machine.Unexpected(AbstractStateMachine::WARNING,machine.GetDataMap().GetLastError());
            }
            break;
        default:
            SYNTAX_ERROR_HANDLER(SYM_NUM)
            break;
    }
    return ret;
}

PS20::PS20() :
    AbstractState("PS20")
{

}
