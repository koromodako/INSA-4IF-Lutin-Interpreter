#include "ps27.h"
#include "../rules.h"

int PS27::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
        case S_CONST:///< mot-clé 'const'
            machine.Reduce(RULE_7);
            break;
        case S_VAR:///< mot-clé 'var'
            machine.Reduce(RULE_7);
            break;
        case S_READ:///< 'lire'
            machine.Reduce(RULE_7);
            break;
        case S_WRITE:///< 'ecrire'
            machine.Reduce(RULE_7);
            break;
        case S_ID:///< identifiant '\w[\w\d]*'
            machine.Reduce(RULE_7);
            break;
        case S_EOF:///< $
            machine.Reduce(RULE_7);
            break;
        default:
            machine.Unexpected(symbol);
            return -1;
            break;
    }
    return 0;
}

PS27::PS27() :
    AbstractPS("PS27")
{

}
