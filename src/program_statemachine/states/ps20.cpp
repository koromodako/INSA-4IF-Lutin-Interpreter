#include "ps20.h"
#include "ps21.h"

int PS20::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
        case S_NUM:///< nombre '\d+'
            machine.PileUp(symbol, new PS21());
            break;
        default:
            machine.Unexpected(symbol,this);
            break;
    }
    return -1;
}

PS20::PS20() :
    AbstractPS("PS20")
{

}
