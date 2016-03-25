#include "es14.h"
#include "es15.h"
#include "es2.h"
#include "es3.h"

AbstractState::TransitionResult ES14::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_PF:
        machine.GetInstructionList().AppendSymbol(symbol); // on ajoute le symbole PF
        machine.PileUp(symbol, new ES15);
        ret = AbstractState::PILED_UP;
        break;
    case S_PLUS:
        machine.GetInstructionList().AppendSymbol(symbol);  // on ajoute le symbole PLUS
        machine.PileUp(symbol, new ES2);
        ret = AbstractState::PILED_UP;
        break;
    case S_MINUS:
        machine.GetInstructionList().AppendSymbol(symbol);  // on ajoute le symbole MINUS
        machine.PileUp(symbol, new ES3);
        ret = AbstractState::PILED_UP;
        break;
    default:
        SYNTAX_ERROR_HANDLER(SYM_PLUS)
        break;
    }
    return ret;
}

ES14::ES14() :
    AbstractState("ES14")
{

}
