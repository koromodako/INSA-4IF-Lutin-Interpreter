#include "ps12.h"
#include "ps13.h"
#include "../rules.h"

int PS12::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_V:///< ','
        machine.Reduce(RULE_3);
        break;
    case S_PV:///< ';'
        machine.Reduce(RULE_3);
        break;
    case S_LV:
        machine.PileUp(symbol, new PS13());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS12::PS12() :
    AbstractPS("PS12")
{

}
