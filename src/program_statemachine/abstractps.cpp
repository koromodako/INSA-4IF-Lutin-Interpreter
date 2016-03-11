#include "abstractps.h"

int AbstractPS::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    // default transition
    return -1;
}

AbstractPS::AbstractPS(const string & name) :
    AbstractState(name)
{

}
