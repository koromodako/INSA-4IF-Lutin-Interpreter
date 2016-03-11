#include "abstractstatemachine.h"

void AbstractStateMachine::Reduce(int size)
{
    while (size != 0 && !_statesStack.empty()) {
        delete _statesStack.top();
        _statesStack.pop();
        _symbolsStack.pop();
        size--;
    }
}

void AbstractStateMachine::PileUp(Symbol symbol, AbstractState *state)
{
    _statesStack.push(state);
    _symbolsStack.push(symbol);
}

void AbstractStateMachine::Unexpected(Symbol symbol)
{
    /// \todo implement here
}

AbstractStateMachine::AbstractStateMachine(Lexer &lexer, DataMap &dmap, InstructionList &instructions) :
    _lexer(lexer),
    _dMap(dmap),
    _instructions(instructions),
    _errorsStack(),
    _symbolsStack(),
    _statesStack()
{
}
