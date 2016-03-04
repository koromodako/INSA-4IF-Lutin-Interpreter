#include "es0.h"

int ES0::transition(ExpressionStateMachine &machine, Symbol symbol)
{
    //default transition
    return -1;
}

ES0::ES0() :
    AbstractES("ES0")
{

}
