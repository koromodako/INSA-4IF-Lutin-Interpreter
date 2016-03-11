#include "es6.h"
#include "es8.h"
#include "es9.h"
#include "es10.h"
#include "es11.h"

int ES6::Transition(ExpressionStateMachine &machine, Symbol symbol)
{
    int ret = 0;
    switch (symbol.code) {
    case S_ID:
        machine.PileUp(symbol, new ES9);
        break;
    case S_NUM:
        machine.PileUp(symbol, new ES10);
        break;
    case S_PF:
        machine.PileUp(symbol, new ES11);
        break;
    case S_F:
        machine.PileUp(symbol, new ES8);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES6::ES6() :
    AbstractES("ES6")
{

}
