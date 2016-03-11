#include "ps2.h"
#include "../rules.h"
#include "ps3.h"
int PS2::Transition(ProgramStateMachine &machine, Symbol symbol)
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
    case S_LI:///< liste d'instructions
        machine.PileUp(symbol, new PS3());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS2::PS2() :
    AbstractPS("PS2")
{

}
