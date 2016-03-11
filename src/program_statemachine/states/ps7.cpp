#include "ps7.h"

#include "ps8.h"
int PS7::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_PV:///< ';'
        machine.PileUp(symbol, new PS8());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS7::PS7() :
    AbstractPS("PS7")
{

}
