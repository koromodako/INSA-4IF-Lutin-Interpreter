#include "es5.h"
#include "es9.h"
#include "es10.h"
#include "es11.h"
#include "es7.h"

int ES5::Transition(ExpressionStateMachine &machine, Symbol symbol)
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
        machine.PileUp(symbol, new ES7);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES5::ES5() :
    AbstractES("ES5")
{

}
