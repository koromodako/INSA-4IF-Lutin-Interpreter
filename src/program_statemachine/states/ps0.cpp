#include "ps0.h"

int PS0::transition(ProgramStateMachine &machine, ProgramStateMachine::Symbol symbol)
{
    // default transition
    return -1;
}

PS0::PS0() :
    AbstractPS("AbstractPS")
{

}
