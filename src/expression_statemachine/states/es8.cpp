#include "es8.h"
#include "../rules.h"

int ES8::Transition(ExpressionStateMachine &machine, Symbol symbol)
{
    int ret = 0;
    switch (symbol.code) {
    case S_EOF:
        machine.Reduce(RULE_6);
        break;
    case S_PF:
        machine.Reduce(RULE_6);
        break;
    case S_PLUS:
        machine.Reduce(RULE_6);
        break;
    case S_MINUS:
        machine.Reduce(RULE_6);
        break;
    case S_MULT:
        machine.Reduce(RULE_6);
        break;
    case S_DIV:
        machine.Reduce(RULE_6);
        break;
    case S_PV:
        machine.Reduce(RULE_6);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES8::ES8() :
    AbstractES("ES8")
{

}
