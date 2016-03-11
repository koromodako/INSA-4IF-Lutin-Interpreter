#include "ps18.h"
#include "ps19.h"

int PS18::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.PileUp(symbol, new PS19());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS18::PS18() :
    AbstractPS("PS18")
{

}
