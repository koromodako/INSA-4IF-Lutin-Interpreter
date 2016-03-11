#include "ps16.h"
#include "../rules.h"
int PS16::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_CONST:///< mot-clé 'const'
        machine.Reduce(RULE_6);
        break;
    case S_VAR:///< mot-clé 'var'
        machine.Reduce(RULE_6);
        break;
    case S_READ:///< 'lire'
        machine.Reduce(RULE_6);
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(RULE_6);
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(RULE_6);
        break;
    case S_EOF:///< $
        machine.Reduce(RULE_6);
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS16::PS16() :
    AbstractPS("PS16")
{

}
