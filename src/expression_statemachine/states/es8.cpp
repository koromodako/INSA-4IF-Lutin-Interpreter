#include "es8.h"

int ES8::transition(ExpressionStateMachine &machine, ExpressionStateMachine::Symbol symbol)
{
    //default transition
    return -1;
}

ES8::ES8() :
    AbstractES("AbstractES")
{

}
