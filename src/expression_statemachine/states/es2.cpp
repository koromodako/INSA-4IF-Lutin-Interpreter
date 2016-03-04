#include "es2.h"

int ES2::transition(ExpressionStateMachine &machine, ExpressionStateMachine::Symbol symbol)
{
    //default transition
    return -1;
}

ES2::ES2() :
    AbstractES("AbstractES")
{

}
