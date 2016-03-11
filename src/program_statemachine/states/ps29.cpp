#include "ps29.h"
#include "../rules.h"
#include "../../expression_statemachine/expressionstatemachine.h"

AbstractState::TransitionResult PS29::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    ExpressionStateMachine expStateMachine(
                machine.GetLexer(), machine.GetDataMap(),
                machine.GetInstructionList());
    expStateMachine.Run();
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
        default:
            machine.Unexpected(symbol);
            break;
    }
    return ret;
}

PS29::PS29() :
    AbstractState("PS29")
{

}
