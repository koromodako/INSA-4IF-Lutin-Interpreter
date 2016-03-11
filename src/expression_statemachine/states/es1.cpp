#include "es1.h"
#include "es2.h"
#include "es3.h"
#include "es17.h"

int ES1::Transition(ExpressionStateMachine &machine, Symbol symbol)
{
    int ret = 0;
    switch (symbol.code) {
    case S_PLUS:
        machine.PileUp(symbol, new ES2);
        break;
    case S_MINUS:
        machine.PileUp(symbol, new ES3);
        break;
    case S_PV:
        machine.PileUp(symbol, new ES17);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES1::ES1() :
    AbstractES("ES1")
{

}
