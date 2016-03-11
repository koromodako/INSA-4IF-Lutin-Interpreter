#include "ps14.h"
#include "ps15.h"

int PS14::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.GetDataMap().StartVar(symbol.buf);
        machine.PileUp(symbol, new PS15());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS14::PS14() :
    AbstractPS("PS14")
{

}
