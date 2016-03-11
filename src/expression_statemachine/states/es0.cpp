#include "es0.h"
#include "es9.h"
#include "es10.h"
#include "es11.h"
#include "es1.h"
#include "es16.h"
#include "es12.h"

int ES0::Transition(ExpressionStateMachine &machine, Symbol symbol)
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
    case S_A:
        machine.PileUp(symbol, new ES1);
        break;
    case S_T:
        machine.PileUp(symbol, new ES16);
        break;
    case S_F:
        machine.PileUp(symbol, new ES12);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES0::ES0() : AbstractES("ES0") {}
