#include "abstractstatemachine.h"

void AbstractStateMachine::reduce(int symbole, AbstractState *state)
{
    /// \todo implement here
}

void AbstractStateMachine::unexpected(int symbole, AbstractState *state)
{
    /// \todo implement here
}

AbstractStateMachine::AbstractStateMachine() :
    _symbols_stack(), _state_stack()
{
}
