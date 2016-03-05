#include "expressionstatemachine.h"

ExpressionStateMachine::ExpressionStateMachine(Lexer & lexer) :
    AbstractStateMachine(lexer),
    _expr(NULL)
{

}
