#include "abstractstatemachine.h"

void AbstractStateMachine::Reduce(int size)
{
    while (size != 0 && !_state_stack.empty()) {
        delete _state_stack.top();
        _state_stack.pop();
        _symbols_stack.pop();
        size--;
    }
}

void AbstractStateMachine::PileUp(Symbol symbol, AbstractState *state)
{
    _state_stack.push(state);
    _symbols_stack.push(symbol);
}

void AbstractStateMachine::Unexpected(Symbol symbol)
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
