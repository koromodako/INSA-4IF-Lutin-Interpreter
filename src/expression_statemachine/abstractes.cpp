#include "abstractes.h"

int AbstractES::transition(ExpressionStateMachine &machine, ExpressionStateMachine::Symbol symbol)
{
    //default transition
    return -1;
}

AbstractES::AbstractES(const string & name) :
    AbstractState(name)
{

}
