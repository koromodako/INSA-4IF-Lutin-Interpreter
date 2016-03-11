#include "ps28.h"
#include "../rules.h"

int PS28::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
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
            machine.Unexpected(symbol,this);
            break;
    }
    return -1;
}

PS28::PS28() :
    AbstractPS("PS28")
{

}
