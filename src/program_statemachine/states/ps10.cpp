#include "ps10.h"
#include "ps28.h"

int PS10::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_EXP:///< expression arithmetique
        machine.PileUp(symbol, new PS28());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS10::PS10() :
    AbstractPS("PS10")
{

}
