#include "ps16.h"

int PS16::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_CONST:///< mot-clé 'const'
        machine.Reduce();
        break;
    case S_VAR:///< mot-clé 'var'
        machine.Reduce();
        break;
    case S_READ:///< 'lire'
        machine.Reduce();
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce();
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce();
        break;
    case S_EOF:///< $
        machine.Reduce();
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
