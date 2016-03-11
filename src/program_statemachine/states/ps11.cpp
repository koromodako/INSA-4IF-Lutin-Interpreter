#include "ps11.h"
#include "ps12.h"

int PS11::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_ID:///< 'id'
        machine.GetDataMap().StartVar(symbol.buf);
        machine.PileUp(symbol, new PS12());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS11::PS11() :
    AbstractPS("PS11")
{

}
