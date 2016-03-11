#include "es1.h"
#include "es2.h"
#include "es3.h"
#include "es17.h"

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
        machine.PileUp(symbol, new ES17);
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;
}

ES1::ES1() :
    AbstractState("ES1")
{

}
