#include "es8.h"
#include "../rules.h"

AbstractState::TransitionResult ES8::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EOF:
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_PF:
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_PLUS:
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_MINUS:
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_MULT:
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_DIV:
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_6);
        ret = AbstractState::REDUCED;
        break;
    case S_PV:
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_6);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;
}

ES8::ES8() :
    AbstractState("ES08")
{

}
