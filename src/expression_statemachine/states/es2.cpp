#include "es2.h"
#include "es9.h"
#include "es10.h"
#include "es11.h"
#include "es4.h"

int ES2::Transition(ExpressionStateMachine &machine, Symbol symbol)
{
    int ret = 0;
    switch (symbol.code) {
    case S_ID:
        machine.PileUp(symbol, new ES9);
        break;
    case S_NUM:
        machine.PileUp(symbol, new ES10);
        break;
    case S_PO:
        machine.PileUp(symbol, new ES11);
        break;
    case S_T:
        machine.PileUp(symbol, new ES4);
        break;
    case S_F:
        machine.PileUp(symbol, new ES2);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES2::ES2() :
    AbstractES("ES2")
{

}
