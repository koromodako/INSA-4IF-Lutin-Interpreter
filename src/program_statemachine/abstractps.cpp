#include "abstractps.h"

int AbstractPS::transition(ProgramStateMachine &machine, ProgramStateMachine::Symbol symbol)
{
    // default transition
    return -1;
}

AbstractPS::AbstractPS(const string & name) :
    AbstractState(name)
{

}
