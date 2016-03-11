#include "ps15.h"
#include "../rules.h"

int PS15::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_V:///< ','
        machine.Reduce(RULE_2);
        break;
    case S_PV:///< ';'
        machine.Reduce(RULE_2);
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS15::PS15() :
    AbstractPS("PS15")
{

}
