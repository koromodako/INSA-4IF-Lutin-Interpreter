#include "ps10.h"
#include "ps28.h"

int PS10::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_EXP:///< expression arithmetique
        //machine.GetDataMap().SetDataValue(symbol.buf); autre automate
        machine.PileUp(symbol, new PS28());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS10::PS10() :
    AbstractPS("PS10")
{

}
