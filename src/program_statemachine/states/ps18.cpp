#include "ps18.h"
#include "ps19.h"

AbstractState::TransitionResult PS18::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        // on initie la transaction d'insertion d'une constante
        machine.GetDataMap().StartConst(symbol.buf);
        // cette transaction se terminera lors de l'affectation dans l'état 20
        machine.PileUp(symbol, new PS19());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::ErrorType::SYNTAX_ERROR, symbol);
        break;
    }
    return ret;
}

PS18::PS18() :
    AbstractState("PS18")
{

}
