#include "ps22.h"
#include "ps23.h"
#include "ps27.h"

int PS22::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
        case S_V:///< ','
            machine.PileUp(symbol, new PS23());
            break;
        case S_PV:///< ';'
            machine.GetInstructionList().EndInstruction();
            machine.PileUp(symbol, new PS27());
            break;
        default:
            machine.Unexpected(symbol);
            return -1;
            break;
    }
    return 0;
}

PS22::PS22() :
    AbstractPS("PS22")
{

}
