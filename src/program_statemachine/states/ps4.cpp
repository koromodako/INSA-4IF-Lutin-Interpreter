#include "ps4.h"
#include "../rules.h"

int PS4::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {

    case S_READ:///< 'lire'
        machine.Reduce(RULE_10);
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(RULE_10);
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(RULE_10);
        break;
    case S_EOF:///< $
        machine.Reduce(RULE_10);
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
