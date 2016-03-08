#include "abstractstatemachine.h"

void AbstractStateMachine::reduce(int symbole, AbstractState *state)
{
    /// \todo implement here
}

void AbstractStateMachine::unexpected(int symbole, AbstractState *state)
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
