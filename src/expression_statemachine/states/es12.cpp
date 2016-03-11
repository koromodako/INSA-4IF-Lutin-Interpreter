#include "es12.h"
#include "../rules.h"

int ES12::Transition(ExpressionStateMachine &machine, Symbol symbol)
{
    int ret = 0;
    switch (symbol.code) {
    case S_EOF:
        machine.Reduce(RULE_7);
        break;
    case S_PF:
        machine.Reduce(RULE_7);
        break;
    case S_PLUS:
        machine.Reduce(RULE_7);
        break;
    case S_MINUS:
        machine.Reduce(RULE_7);
        break;
    case S_MULT:
        machine.Reduce(RULE_7);
        break;
    case S_DIV:
        machine.Reduce(RULE_7);
        break;
    case S_PV:
        machine.Reduce(RULE_7);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES12::ES12() :
    AbstractES("ES12")
{

}
