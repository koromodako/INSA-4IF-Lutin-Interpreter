#include "programstatemachine.h"
#include "states/ps0.h"

ProgramStateMachine::ProgramStateMachine(Lexer &lexer, DataMap &dmap, InstructionList &instructions) :
    AbstractStateMachine(lexer, dmap, instructions)
{
}

void ProgramStateMachine::Run(AbstractState *initialState)
{
    (void)initialState;
    // -- initialize lexer with a first move forward
    GetLexer().MoveForward();
    // -- run state machine
    AbstractStateMachine::Run(new PS0);
}
