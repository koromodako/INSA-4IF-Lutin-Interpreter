#include "ps9.h"

#include "ps10.h"

AbstractState::TransitionResult PS9::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_AFFECT:///< ':='
        machine.PileUp(symbol, new PS10());
        ret = AbstractState::PILED_UP;
        break;
    default:
        if(machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_AFFECT))
        {   Transition(machine, SYM_AFFECT);
        }
        break;
    }
    return ret;
}

PS9::PS9() :
    AbstractState("PS09")
{

}
