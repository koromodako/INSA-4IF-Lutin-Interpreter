#include "ps2.h"

int PS2::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
    case S_READ:///< 'lire'
        break;
    case S_WRITE:///< 'ecrire'
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        break;
    case S_EOF:///< $
        break;
    case S_LI:///< liste d'instructions
        machine.PileUp(symbol, new PS3("PS3"));
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS2::PS2() :
    AbstractPS("PS2")
{

}
