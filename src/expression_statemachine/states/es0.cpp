#include "es0.h"
#include "es9.h"
#include "es10.h"
#include "es11.h"
#include "es1.h"
#include "es16.h"
#include "es12.h"

AbstractState::TransitionResult ES0::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_ID:
        machine.GetInstructionList().AppendSymbol(symbol);  // on ajoute le symbole ID
        machine.GetDataMap().AddIfNotExist(symbol.buf);
        machine.PileUp(symbol, new ES9);
        ret = AbstractState::PILED_UP;
        break;
    case S_NUM:
        machine.GetInstructionList().AppendSymbol(symbol);  // on ajoute le symbole NUM
        machine.PileUp(symbol, new ES10);
        ret = AbstractState::PILED_UP;
        break;
    case S_PO:
        machine.GetInstructionList().AppendSymbol(symbol); // on ajoute le symbole PO
        machine.PileUp(symbol, new ES11);
        ret = AbstractState::PILED_UP;
        break;
    case S_A:
        machine.PileUp(symbol, new ES1);
        ret = AbstractState::PILED_UP;
        break;
    case S_T:
        machine.PileUp(symbol, new ES16);
        ret = AbstractState::PILED_UP;
        break;
    case S_F:
        machine.PileUp(symbol, new ES12);
        ret = AbstractState::PILED_UP;
        break;
    default:
        SYNTAX_ERROR_HANDLER(SYM_ID)
        break;
    }
    return ret;
}

ES0::ES0() : AbstractState("ES00") {}
