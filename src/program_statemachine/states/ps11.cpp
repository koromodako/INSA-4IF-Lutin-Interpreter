#include "ps11.h"
#include "ps12.h"

int PS11::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_WRITE:///< 'ecrire'
        machine.PileUp(symbol, new PS12());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS11::PS11() :
    AbstractPS("PS11")
{

}
