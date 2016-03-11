#include "ps20.h"
#include "ps21.h"

int PS20::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
        case S_NUM:///< nombre '\d+'
            machine.GetDataMap().SetDataValue(symbol.buf);
            machine.GetDataMap().EndData();
            machine.PileUp(symbol, new PS21());
            break;
        default:
            machine.Unexpected(symbol);
            return -1;
            break;
    }
    return 0;
}

PS20::PS20() :
    AbstractPS("PS20")
{

}
