#include "abstractstatemachine.h"

void AbstractStateMachine::Reduce(Symbol symbol, AbstractState *state, int size)
{

}

void AbstractStateMachine::PileUp(Symbol symbol, AbstractState *state)
{

}

void AbstractStateMachine::Unexpected(Symbol symbol, AbstractState *state)
{
    /// \todo implement here
}

AbstractStateMachine::AbstractStateMachine(Lexer &lexer, DataMap &dmap, InstructionList &instructions) :
    _lexer(lexer),
    _dmap(dmap),
    _instructions(instructions),
    _error_stack(),
    _symbols_stack(),
    _state_stack()
{
}
