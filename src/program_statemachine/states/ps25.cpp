#include "ps25.h"
#include "ps26.h"

int PS25::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
        case S_NUM:///< nombre '\d+'
            machine.PileUp(symbol, new PS26());
            break;
        default:
            machine.Unexpected(symbol);
            break;
    }
    return -1;
}

PS25::PS25() :
    AbstractPS("PS25")
{

}
