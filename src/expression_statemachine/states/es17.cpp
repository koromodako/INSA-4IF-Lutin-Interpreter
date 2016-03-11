#include "es17.h"
#include "../rules.h"

int ES17::Transition(ExpressionStateMachine &machine, Symbol symbol)
{
    int ret = 0;
    switch (symbol.code) {
    case S_EOF:
        machine.Reduce(RULE_1);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES17::ES17() :
    AbstractES("ES17")
{

}
