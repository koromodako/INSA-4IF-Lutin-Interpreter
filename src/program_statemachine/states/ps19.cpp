#include "ps19.h"
#include "ps20.h"

int PS19::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_EQ:///< nombre '\d+'
        machine.PileUp(symbol, new PS20());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS19::PS19() :
    AbstractPS("PS19")
{

}
