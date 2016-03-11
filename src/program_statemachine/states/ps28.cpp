#include "ps28.h"
#include "../rules.h"
#include "../../expression_statemachine/expressionstatemachine.h"

int PS28::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    ExpressionStateMachine* expStateMachine = new ExpressionStateMachine(
                machine.GetLexer(), machine.GetDataMap(),
                machine.GetInstructionList());
    //expStateMachine.Run();
    delete(expStateMachine);
    switch (symbol.code) {
        case S_READ:///< 'lire'
            machine.Reduce(RULE_12);
            break;
        case S_WRITE:///< 'ecrire'
            machine.Reduce(RULE_12);
            break;
        case S_ID:///< identifiant '\w[\w\d]*'
            machine.Reduce(RULE_12);
            break;
        case S_EOF:///< $
            machine.Reduce(RULE_12);
            break;
        default:
            machine.Unexpected(symbol);
            break;
    }
    return -1;
}

PS28::PS28() :
    AbstractPS("PS28")
{

}
