#include "ps19.h"
#include "ps20.h"

int PS19::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_NUM:///< nombre '\d+'
        machine.PileUp(symbol, new PS20());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS19::PS19() :
    AbstractPS("PS19")
{

}
