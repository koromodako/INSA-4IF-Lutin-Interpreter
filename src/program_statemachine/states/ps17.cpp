#include "ps17.h"
#include "../rules.h"

int PS17::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_CONST:///< mot-clé 'const'
        machine.Reduce(RULE_4);
        break;
    case S_VAR:///< mot-clé 'var'
        machine.Reduce(RULE_4);
        break;
    case S_READ:///< 'lire'
        machine.Reduce(RULE_4);
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(RULE_4);
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(RULE_4);
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS17::PS17() :
    AbstractPS("PS17")
{

}
