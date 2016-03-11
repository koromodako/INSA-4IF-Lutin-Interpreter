#include "ps13.h"
#include "ps14.h"
#include "ps16.h"

int PS13::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_V:///< ','
        machine.PileUp(symbol, new PS14());
        break;
    case S_PV:///< ';'
        machine.PileUp(symbol, new PS16());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS13::PS13() :
    AbstractPS("PS13")
{

}
