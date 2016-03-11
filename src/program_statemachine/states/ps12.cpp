#include "ps12.h"
#include "ps13.h"

int PS12::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_V:///< ','
        machine.Reduce();
        break;
    case S_PV:///< ';'
        machine.Reduce();
        break;
    case S_I:///< instruction
        machine.PileUp(symbol, new PS13());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS12::PS12() :
    AbstractPS("PS12")
{

}
