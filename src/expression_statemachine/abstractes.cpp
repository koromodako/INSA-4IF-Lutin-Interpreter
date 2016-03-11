#include "abstractes.h"

int AbstractES::Transition(ExpressionStateMachine &machine, Symbol symbol)
{
    //default transition
    return -1;
}

AbstractES::AbstractES(const string & name) :
    AbstractState(name)
{

}
