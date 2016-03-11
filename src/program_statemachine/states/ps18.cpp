#include "ps18.h"
#include "ps19.h"

int PS18::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.GetDataMap().StartConst(symbol.buf);
        machine.PileUp(symbol, new PS19());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS18::PS18() :
    AbstractPS("PS18")
{

}
