#include "ps23.h"
#include "ps24.h"

int PS23::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
        case S_ID:///< identifiant '\w[\w\d]*'
            machine.PileUp(symbol, new PS24());
            break;
        default:
            machine.Unexpected(symbol,this);
            break;
    }
    return -1;
}

PS23::PS23() :
    AbstractPS("PS23")
{

}
