#include "ps2.h"
#include "../rules.h"
#include "ps3.h"
AbstractState::TransitionResult PS2::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_READ:///< 'lire'
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_10);
        ret = AbstractState::REDUCED;
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_10);
        ret = AbstractState::REDUCED;
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_10);
        ret = AbstractState::REDUCED;
        break;
    case S_EOF:///< $
        machine.Reduce(Symbol(S_LEXER_ERROR), RULE_10);
        ret = AbstractState::REDUCED;
        break;
    case S_LI:///< liste d'instructions
        machine.PileUp(symbol, new PS3());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;
}

PS2::PS2() :
    AbstractState("PS02")
{

}
