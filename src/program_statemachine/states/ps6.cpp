#include "ps6.h"

#include "ps7.h"

AbstractState::TransitionResult PS6::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        // on ajoute l'instruction de lecture
        machine.GetInstructionList().StartRead(symbol.buf);
        // la validation de la transaction se fera dans l'état 8 qui doit suivre l'état 7
        machine.PileUp(symbol, new PS7());
        ret = AbstractState::PILED_UP;
        break;
    default:
        if(machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_ID))
        {   Transition(machine, SYM_ID);
        }
        break;
    }
    return ret;
}

PS6::PS6() :
    AbstractState("PS06")
{

}
