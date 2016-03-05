#include "abstractstatemachine.h"

void AbstractStateMachine::reduce(int symbole, AbstractState *state)
{
    /// \todo implement here
}

void AbstractStateMachine::unexpected(int symbole, AbstractState *state)
{
    /// \todo implement here
}

AbstractStateMachine::AbstractStateMachine(Lexer &lexer) :
    _lexer(lexer),
    _error_stack(),
    _symbols_stack(),
    _state_stack()
{
}
