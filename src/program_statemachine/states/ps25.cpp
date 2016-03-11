#include "ps25.h"
#include "ps26.h"

int PS25::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
        case S_NUM:///< nombre '\d+'
            machine.GetDataMap().SetDataValue(symbol.buf);
            machine.GetDataMap().EndData();
            machine.PileUp(symbol, new PS26());
            break;
        default:
            machine.Unexpected(symbol);
            return -1;
            break;
    }
    return 0;
}

PS25::PS25() :
    AbstractPS("PS25")
{

}
