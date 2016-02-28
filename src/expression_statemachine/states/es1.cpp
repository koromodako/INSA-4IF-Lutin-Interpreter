#include "es1.h"

int ES1::transition(ExpressionStateMachine &machine, ExpressionStateMachine::Symbol symbol)
{
    //default transition
    return -1;
}

ES1::ES1() :
    AbstractES("AbstractES")
{

}
