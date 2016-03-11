#include "es4.h"
#include "es5.h"
#include "es6.h"
#include "../rules.h"

int ES4::Transition(ExpressionStateMachine &machine, Symbol symbol)
{
    int ret = 0;
    switch (symbol.code) {
    case S_PF:
        machine.Reduce(RULE_2);
        break;
    case S_PLUS:
        machine.Reduce(RULE_2);
        break;
    case S_MINUS:
        machine.Reduce(RULE_2);
        break;
    case S_MULT:
        machine.PileUp(symbol, new ES5);
        break;
    case S_DIV:
        machine.PileUp(symbol, new ES6);
        break;
    case S_PV:
        machine.Reduce(RULE_2);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES4::ES4() :
    AbstractES("ES4")
{

}
