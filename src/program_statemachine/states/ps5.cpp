#include "ps5.h"

#include "ps29.h"
int PS5::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
    case S_EXP:///< expression arithmetique
        machine.PileUp(symbol, new PS29());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS5::PS5() :
    AbstractPS("PS5")
{

}
