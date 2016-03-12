#include "es1.h"
#include "es2.h"
#include "es3.h"
#include "es17.h"
#include "../rules.h"

AbstractState::TransitionResult ES1::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_PLUS:
        machine.GetInstructionList().AppendSymbol(symbol);
        machine.PileUp(symbol, new ES2);
        ret = AbstractState::PILED_UP;
        break;
    case S_MINUS:
        machine.GetInstructionList().AppendSymbol(symbol);
        machine.PileUp(symbol, new ES3);
        ret = AbstractState::PILED_UP;
        break;
    case S_PV:
        /*
         *  Normalement on empile E17 mais là on doit accepter,
         *  l'equation est terminée. L'état E17 ne sert donc à rien.
         *  => On se contente juste d'accepter
         */
        ret = AbstractState::ACCEPT;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;
}

ES1::ES1() :
    AbstractState("ES01")
{

}
