#include "ps28.h"
#include "../rules.h"
#include "../../expression_statemachine/expressionstatemachine.h"

AbstractState::TransitionResult PS28::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_READ:///< 'lire'
            machine.GetInstructionList().EndInstruction();
            machine.Reduce(SYM_I, RULE_12);
            ret = AbstractState::REDUCED;
            break;
        case S_WRITE:///< 'ecrire'
            machine.GetInstructionList().EndInstruction();
            machine.Reduce(SYM_I, RULE_12);
            ret = AbstractState::REDUCED;
            break;
        case S_ID:///< identifiant '\w[\w\d]*'
            machine.GetInstructionList().EndInstruction();
            machine.Reduce(SYM_I, RULE_12);
            ret = AbstractState::REDUCED;
            break;
        case S_EOF:///< $
            machine.GetInstructionList().EndInstruction();
            machine.Reduce(SYM_I, RULE_12);
            break;
        default:
            machine.Unexpected(symbol);
            break;
    }
    return ret;
}

PS28::PS28() :
    AbstractState("PS28")
{

}
