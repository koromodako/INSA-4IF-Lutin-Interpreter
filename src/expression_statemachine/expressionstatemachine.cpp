#include "expressionstatemachine.h"
#include "states/es0.h"

ExpressionStateMachine::ExpressionStateMachine(Lexer & lexer, DataMap & dmap, InstructionList & instructions) :
    AbstractStateMachine(lexer, dmap, instructions)
{
}

bool ExpressionStateMachine::Run(AbstractState*)
{
    // -- run state machine
    return AbstractStateMachine::Run(new ES0);
}
