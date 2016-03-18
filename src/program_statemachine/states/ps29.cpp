#include "ps29.h"
#include "../rules.h"
#include "../../expression_statemachine/expressionstatemachine.h"

AbstractState::TransitionResult PS29::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
        case S_READ:///< 'lire'
            machine.GetInstructionList().EndInstruction();
            machine.Reduce(SYM_I, RULE_10);
            ret = AbstractState::REDUCED;
            break;
        case S_WRITE:///< 'ecrire'
            machine.GetInstructionList().EndInstruction();
            machine.Reduce(SYM_I, RULE_10);
            ret = AbstractState::REDUCED;
            break;
        case S_ID:///< identifiant '\w[\w\d]*'
            machine.GetInstructionList().EndInstruction();
            machine.Reduce(SYM_I, RULE_10);
            ret = AbstractState::REDUCED;
            break;
        case S_EOF:///< $
            machine.GetInstructionList().EndInstruction();
            machine.Reduce(SYM_I, RULE_10);
            ret = AbstractState::REDUCED;
            break;
        default:
            machine.Unexpected(AbstractStateMachine::ERROR, "Illegal expression");
            break;
    }
    return ret;
}

PS29::PS29() :
    AbstractState("PS29")
{
}
