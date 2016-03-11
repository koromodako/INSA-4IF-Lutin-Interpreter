#include "ps0.h"

#include "ps1.h"
#include "../rules.h"

int PS0::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
    case S_CONST:///< mot-clé 'const'
        machine.Reduce(RULE_3);
        break;
    case S_VAR:///< mot-clé 'var'
        machine.Reduce(RULE_3);
        break;
    case S_READ:///< 'lire'
        machine.Reduce(RULE_3);
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(RULE_3);
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(RULE_3);
        break;
    case S_LD:///< liste de déclarations
        machine.PileUp(symbol, new PS1());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS0::PS0() :
    AbstractPS("PS0")
{

}
