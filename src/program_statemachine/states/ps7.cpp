#include "ps7.h"

int PS7::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
    case S_PV:///< ';'
        machine.PileUp(symbol, new PS8("PS8"));
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
