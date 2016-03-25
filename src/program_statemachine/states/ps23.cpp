#include "ps23.h"
#include "ps24.h"

AbstractState::TransitionResult PS23::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_ID:///< identifiant '\w[\w\d]*'
            // on initie la transaction d'insertion d'une constante
            machine.GetDataMap().StartConst(symbol.buf);
            // cette transaction se terminera lors de l'affectation dans l'état 25
            machine.PileUp(symbol, new PS24());
            ret = AbstractState::PILED_UP;
            break;
        default:
            machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_ID);
            break;
    }
    return ret;
}

PS23::PS23() :
    AbstractState("PS23")
{

}
