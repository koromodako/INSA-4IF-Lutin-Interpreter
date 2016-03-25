#include "es13.h"
#include "es5.h"
#include "es6.h"
#include "../rules.h"

AbstractState::TransitionResult ES13::Transition(AbstractStateMachine &machine, const Symbol & symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_PF:
        machine.Reduce(SYM_A, RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_PLUS:
        machine.Reduce(SYM_A, RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_MINUS:
        machine.Reduce(SYM_A, RULE_3);
        ret = AbstractState::REDUCED;
        break;
    case S_MULT:
        machine.GetInstructionList().AppendSymbol(symbol); // on ajoute le symbole MULT
        machine.PileUp(symbol, new ES5);
        ret = AbstractState::PILED_UP;
        break;
    case S_DIV:
        machine.GetInstructionList().AppendSymbol(symbol); // on ajoute le symbole DIV
        machine.PileUp(symbol, new ES6);
        ret = AbstractState::PILED_UP;
        break;
    case S_PV:
        machine.Reduce(SYM_A, RULE_3);
        ret = AbstractState::REDUCED;
        break;
    default:
        if(machine.Unexpected(AbstractStateMachine::SYNTAX_ERROR, SYM_PV))
        {   Transition(machine, SYM_PV);
        }
        break;
    }
    return ret;
}

ES13::ES13() :
    AbstractState("ES13")
{

}
