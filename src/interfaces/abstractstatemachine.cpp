#include "abstractstatemachine.h"

#include "../debug.h"

AbstractStateMachine::~AbstractStateMachine()
{
    // nettoyage de la stack des etats si non vide
    while (!_statesStack.empty()) {
        delete _statesStack.top();
        _statesStack.pop();
    }
}

void AbstractStateMachine::Run(AbstractState * initialState)
{
    // -- DEBUG --------------------------------------------------------
    DEBUG("Running state machine with initial state '" << initialState->name() << "'");
    // -- DEBUG --------------------------------------------------------

    // -- initialize state machine
    _statesStack.push(initialState);
    // -- run state machine
    Symbol symbol;
    bool ok(true), accept(false);
    while(!_statesStack.empty() && ok && !accept)
    {
        symbol = _lexer.GetNext();

        if(symbol.code==S_LEXER_ERROR){
            Unexpected(LEXICAL_ERROR, symbol);
            break;
        }

        switch(_statesStack.top()->Transition(*this, symbol))
        {
        case AbstractState::UNEXPECTED: ok = false; break;
        case AbstractState::REDUCED: break;
        case AbstractState::PILED_UP: _lexer.MoveForward(); break;
        case AbstractState::ACCEPT: accept = true; break;
        }

        // -- DEBUG --------------------------------------------------------
        DEBUG("is back to transition loop");
        // -- DEBUG --------------------------------------------------------

    }

    // -- DEBUG --------------------------------------------------------
    DEBUG("exiting transition loop");
    // -- DEBUG --------------------------------------------------------
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

    // -- DEBUG --------------------------------------------------------
    DEBUG("applying direct transition on reduce");
    // -- DEBUG --------------------------------------------------------

    // transition appliquée quand on arrive dans le nouvel état
    if(!_statesStack.empty())
    {
        // -- DEBUG --------------------------------------------------------
        DEBUG("transition applied");
        // -- DEBUG --------------------------------------------------------

        _statesStack.top()->Transition(*this, symbol);
    }
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

void AbstractStateMachine::Unexpected(ErrorType type, Symbol symbol)
{
    switch(type)
    {
    case LEXICAL_ERROR:
        cerr<<"Lexical Error: ("<<_lexer.GetLine()<<" : "<<_lexer.GetCol()<<") unexpected symbol "<<symbol.buf<<endl;
        break;
    case SYNTAX_ERROR:
        cerr<<"Syntax Error: ("<<_lexer.GetLine()<<" : "<<_lexer.GetCol()<<") expected symbol "<<symbol.buf<<endl;
        break;    
    default:
        break;
    }
}

void AbstractStateMachine::Unexpected(ErrorType type, string message)
{
   if(type == WARNING)
   {
        cerr<<"Warning :"<<message<<endl;
   }
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
