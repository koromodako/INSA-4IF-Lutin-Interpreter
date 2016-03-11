#include "ps24.h"
#include "ps25.h"

int PS24::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
        case S_EQ:///< '='
            machine.PileUp(symbol, new PS25());
            break;
        default:
            machine.Unexpected(symbol,this);
            break;
    }
    return -1;
}

PS24::PS24() :
    AbstractPS("PS24")
{

}
