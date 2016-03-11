#include "ps4.h"

int PS4::Transition(ProgramStateMachine &machine, Symbol symbol)
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
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS4::PS4() :
    AbstractPS("PS4")
{

}
