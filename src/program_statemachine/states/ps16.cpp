#include "ps16.h"

int PS16::transition(ProgramStateMachine &machine, ProgramStateMachine::Symbol symbol)
{
    // default transition
    return -1;
}

PS16::PS16() :
    AbstractPS("AbstractPS")
{

}
