#include "programstatemachine.h"
#include "states/ps0.h"

ProgramStateMachine::ProgramStateMachine(Lexer &lexer, DataMap &dmap, InstructionList &instructions) :
    AbstractStateMachine(lexer, dmap, instructions)
{
}

void ProgramStateMachine::Run()
{
    // -- run state machine
    AbstractStateMachine::Run(new PS0);
}
