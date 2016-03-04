#include "ps4.h"

int PS4::transition(ProgramStateMachine &machine, ProgramStateMachine::Symbol symbol)
{
    // default transition
    return -1;
}

PS4::PS4() :
    AbstractPS("AbstractPS")
{

}
