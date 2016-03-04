#include "ps3.h"

int PS3::transition(ProgramStateMachine &machine, ProgramStateMachine::Symbol symbol)
{
    // default transition
    return -1;
}

PS3::PS3() :
    AbstractPS("AbstractPS")
{

}
