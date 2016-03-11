#include "ps14.h"
#include "ps15.h"

int PS14::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.PileUp(symbol, new PS15());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS14::PS14() :
    AbstractPS("PS14")
{

}
