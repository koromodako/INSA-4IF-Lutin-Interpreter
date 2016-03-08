#include "abstractstatemachine.h"

void AbstractStateMachine::Reduce(int symbole, AbstractState *state, int size)
{
    /// \todo implement here
}

void AbstractStateMachine::Unexpected(int symbole, AbstractState *state)
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
