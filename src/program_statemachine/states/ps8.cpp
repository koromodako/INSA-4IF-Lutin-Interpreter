#include "ps8.h"

#include "../rules.h"

int PS8::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_READ:///< 'lire'
        machine.Reduce(RULE_8);
        break;
    case S_WRITE:///< 'ecrire'
        machine.Reduce(RULE_8);
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.Reduce(RULE_8);
        break;
    case S_EOF:///< $
        machine.Reduce(RULE_8);
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
