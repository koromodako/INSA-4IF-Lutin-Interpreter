#include "es4.h"
#include "es5.h"
#include "es6.h"
#include "../rules.h"

AbstractState::TransitionResult ES4::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_PF:
        machine.Reduce(SYM_A, RULE_2);
        ret = AbstractState::REDUCED;
        break;
    case S_PLUS:
        machine.Reduce(SYM_A, RULE_2);
        ret = AbstractState::REDUCED;
        break;
    case S_MINUS:
        machine.Reduce(SYM_A, RULE_2);
        ret = AbstractState::REDUCED;
        break;
    case S_MULT:
        machine.GetInstructionList().AppendSymbol(symbol);
        machine.PileUp(symbol, new ES5);
        ret = AbstractState::PILED_UP;
        break;
    case S_DIV:
        machine.GetInstructionList().AppendSymbol(symbol);
        machine.PileUp(symbol, new ES6);
        ret = AbstractState::PILED_UP;
        break;
    case S_PV:
        machine.Reduce(SYM_A, RULE_2);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;
}

ES4::ES4() :
    AbstractState("ES04")
{

}
