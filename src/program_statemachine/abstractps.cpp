#include "abstractps.h"

int AbstractPS::transition(ProgramStateMachine &machine, Symbol symbol)
{
    // default transition
    return -1;
}

AbstractPS::AbstractPS(const string & name) :
    AbstractState(name)
{

}
