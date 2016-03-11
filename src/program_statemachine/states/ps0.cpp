#include "ps0.h"

int PS0::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
    case S_CONST:///< mot-clé 'const'
        break;
    case S_VAR:///< mot-clé 'var'
        break;//< '='
    case S_READ:///< 'lire'
        break;
    case S_WRITE:///< 'ecrire'
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        break;
    case S_LD:///< liste de déclarations
        machine.PileUp(symbol, new PS1("PS1"));
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
