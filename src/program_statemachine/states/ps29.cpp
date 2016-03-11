#include "ps29.h"
#include "../rules.h"
#include "../../expression_statemachine/expressionstatemachine.h"

int PS29::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    ExpressionStateMachine* expStateMachine = new ExpressionStateMachine(
                machine.GetLexer(), machine.GetDataMap(),
                machine.GetInstructionList());
    //expStateMachine.Run();
    delete(expStateMachine);
    switch (symbol.code) {
        case S_READ:///< 'lire'
            machine.Reduce(RULE_10);
            break;
        case S_WRITE:///< 'ecrire'
            machine.Reduce(RULE_10);
            break;
        case S_ID:///< identifiant '\w[\w\d]*'
            machine.Reduce(RULE_10);
            break;
        case S_EOF:///< $
            machine.Reduce(RULE_10);
            break;
        default:
            machine.Unexpected(symbol);
            return -1;
            break;
    }
    return 0;
}

PS29::PS29() :
    AbstractPS("PS29")
{

}
