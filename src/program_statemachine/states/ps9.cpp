#include "ps9.h"

#include "ps10.h"

int PS9::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_AFFECT:///< ':='
        machine.PileUp(symbol, new PS10());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS9::PS9() :
    AbstractPS("PS9")
{

}
