#include "ps21.h"
#include "ps22.h"
#include "../rules.h"

int PS21::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
        case S_V:///< ','
            machine.Reduce(RULE_9);
            break;
        case S_PV:///< ';'
            machine.Reduce(RULE_9);
            break;
        case S_LC:///< liste de constantes
            machine.PileUp(symbol, new PS22());
            break;
        default:
            machine.Unexpected(symbol);
            return -1;
            break;
    }
    return 0;
}

PS21::PS21() :
    AbstractPS("PS21")
{

}
