#include "expressionstatemachine.h"
#include "states/es0.h"

ExpressionStateMachine::ExpressionStateMachine(Lexer & lexer, DataMap & dmap, InstructionList & instructions) :
    AbstractStateMachine(lexer, dmap, instructions)
{
}

void ExpressionStateMachine::Run()
{
    // -- run state machine
    AbstractStateMachine::Run(new ES0);
}
