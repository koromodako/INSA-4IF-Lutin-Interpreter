#include "ps23.h"
#include "ps24.h"

int PS23::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
        case S_ID:///< identifiant '\w[\w\d]*'
            machine.GetDataMap().StartConst(symbol.buf);
            machine.PileUp(symbol, new PS24());
            break;
        default:
            machine.Unexpected(symbol);
            return -1;
            break;
    }
    return 0;
}

PS23::PS23() :
    AbstractPS("PS23")
{

}
