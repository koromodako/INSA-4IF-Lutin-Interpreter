#include "ps8.h"

int PS8::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_READ:///< 'lire'
        break;
    case S_WRITE:///< 'ecrire'
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        break;
    case S_EOF:///< $
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS8::PS8() :
    AbstractPS("PS8")
{

}
