#include "es14.h"
#include "es15.h"
#include "es2.h"
#include "es3.h"

int ES14::Transition(ExpressionStateMachine &machine, Symbol symbol)
{
    int ret = 0;
    switch (symbol.code) {
    case S_PF:
        machine.PileUp(symbol, new ES15);
        break;
    case S_PLUS:
        machine.PileUp(symbol, new ES2);
        break;
    case S_MINUS:
        machine.PileUp(symbol, new ES3);
        break;
    default:
        machine.Unexpected(symbol);
        ret = -1;
        break;
    }
    return ret;
}

ES14::ES14() :
    AbstractES("ES14")
{

}
