#include "ps5.h"

#include "ps29.h"
int PS5::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_EXP:///< expression arithmetique
        machine.GetInstructionList().StartPrint();
        machine.PileUp(symbol, new PS29());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS5::PS5() :
    AbstractPS("PS5")
{

}
