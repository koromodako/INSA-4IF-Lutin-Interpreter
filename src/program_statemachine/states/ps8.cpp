#include "ps8.h"

#include "../rules.h"

AbstractState::TransitionResult PS8::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_READ:///< 'lire'
        machine.GetInstructionList().EndInstruction();
        machine.Reduce(SYM_I, RULE_11);
        ret = AbstractState::REDUCED;
        break;
    case S_WRITE:///< 'ecrire'
        machine.GetInstructionList().EndInstruction();
        machine.Reduce(SYM_I, RULE_11);
        ret = AbstractState::REDUCED;
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.GetInstructionList().EndInstruction();
        machine.Reduce(SYM_I, RULE_11);
        ret = AbstractState::REDUCED;
        break;
    case S_EOF:///< $
        machine.GetInstructionList().EndInstruction();
        machine.Reduce(SYM_I, RULE_11);
        ret = AbstractState::REDUCED;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::ErrorType::SYNTAX_ERROR, symbol);
        break;
    }
    return ret;
}

PS8::PS8() :
    AbstractState("PS08")
{

}
