#include "ps7.h"

#include "ps8.h"
int PS7::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_PV:///< ';'
        machine.GetInstructionList().EndInstruction();
        machine.PileUp(symbol, new PS8());
        break;
    default:
        machine.Unexpected(symbol);
        return -1;
        break;
    }
    return 0;
}

PS7::PS7() :
    AbstractPS("PS7")
{

}
