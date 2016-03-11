#include "ps24.h"
#include "ps25.h"

int PS24::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
        case S_EQ:///< '='
            machine.PileUp(symbol, new PS25());
            break;
        default:
            machine.Unexpected(symbol);
            return -1;
            break;
    }
    return 0;
}

PS24::PS24() :
    AbstractPS("PS24")
{

}
