#include "abstractstatemachine.h"

#include "../debug.h"

void AbstractStateMachine::Run(AbstractState * initialState)
{
    // -- DEBUG --------------------------------------------------------
    DEBUG("Running state machine with initial state '" << initialState->name() << "'");
    // -- DEBUG --------------------------------------------------------

    // -- initialize state machine
    _statesStack.push(initialState);
    // -- run state machine
    Symbol symbol;
    bool ok = true;
    while(!_statesStack.empty() && ok)
    {
        symbol = _lexer.GetNext();
        switch(_statesStack.top()->Transition(*this, symbol))
        {
        case AbstractState::UNEXPECTED: ok = false; break;
        case AbstractState::REDUCED: break;
        case AbstractState::PILED_UP: _lexer.MoveForward(); break;
        }
    }
}

void AbstractStateMachine::Reduce(Symbol symbol, int size)
{
    // -- DEBUG --------------------------------------------------------
    DEBUG("current state is '" << _statesStack.top()->name() << "' -> reducing with size=" << size);
    // -- DEBUG --------------------------------------------------------

    while (size != 0 && !_statesStack.empty()) {
        delete _statesStack.top();
        _statesStack.pop();
        _symbolsStack.pop();
        size--;
    }
    // transition appliquée quand on arrive dans le nouvel état
    _statesStack.top()->Transition(*this, symbol);
}

void AbstractStateMachine::PileUp(Symbol symbol, AbstractState *state)
{
    // -- DEBUG --------------------------------------------------------
    DEBUG("current state is '" << _statesStack.top()->name() << "' -> piling up : new state is '" <<
          state->name() << "' symbol(code='"<<symbol.code<<"',buf='"<<symbol.buf<<"')" );
    // -- DEBUG --------------------------------------------------------

    _statesStack.push(state);
    _symbolsStack.push(symbol);
}

void AbstractStateMachine::Unexpected(Symbol symbol)
{
    /// \todo implement here
    // -- DEBUG -------------------------------------------------------------------
    DEBUG("Symbole inattendu dans la machine : symbol(code='"<<symbol.code<<"',buf='"<<symbol.buf<<"')");
    // -- DEBUG -------------------------------------------------------------------
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
