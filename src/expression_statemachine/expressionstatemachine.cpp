#include "expressionstatemachine.h"
#include "states/es0.h"

ExpressionStateMachine::ExpressionStateMachine(Lexer & lexer, DataMap & dmap, InstructionList & instructions) :
    AbstractStateMachine(lexer, dmap, instructions)
{
}

void ExpressionStateMachine::Run()
{
    Symbol symbol;
    bool ok = true;
    while(!getStateStack().empty() && ok)
    {
        symbol = GetLexer().GetNext();
        switch(getStateStack().top()->Transition(*this, symbol))
        {
            case AbstractState::UNEXPECTED: ok = false; break;
            case AbstractState::REDUCED:break;
            case AbstractState::PILED_UP:break;
        }
        GetLexer().MoveForward();

    }
}
