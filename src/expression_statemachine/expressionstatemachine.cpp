#include "expressionstatemachine.h"

ExpressionStateMachine::ExpressionStateMachine(Lexer & lexer, DataMap & dmap, InstructionList & instructions) :
    AbstractStateMachine(lexer, dmap, instructions)
{

}
