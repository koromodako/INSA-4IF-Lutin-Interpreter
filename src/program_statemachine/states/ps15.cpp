#include "ps15.h"

int PS15::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_V:///< ','
        machine.Reduce();
        break;
    case S_PV:///< ';'
        machine.Reduce();
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS15::PS15() :
    AbstractPS("PS15")
{

}
