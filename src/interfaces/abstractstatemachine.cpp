#include "abstractstatemachine.h"

#include "../debug.h"

AbstractStateMachine::~AbstractStateMachine()
{
    // nettoyage de la pile des états si non vide
    while (!_statesStack.empty()) {
        delete _statesStack.top();
        _statesStack.pop();
    }
}

void AbstractStateMachine::Run(AbstractState * initialState)
{
    DEBUG("Running state machine with initial state '" << initialState->name() << "'");
    // initialisation de la machine à états
    _statesStack.push(initialState);
    // boucle d'exécution principale
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

        DEBUG("is back to transition loop");
    }
    DEBUG("exiting transition loop");
}

void AbstractStateMachine::Reduce(const Symbol &symbol, int size)
{
    DEBUG("current state is '" << _statesStack.top()->name() << "' -> reducing with size=" << size);

    while (size != 0 && !_statesStack.empty()) {
        delete _statesStack.top();
        _statesStack.pop();
        _symbolsStack.pop();
        size--;
    }
    DEBUG("applying direct transition on reduce");

    // transition appliquée quand on arrive dans le nouvel état
    if(!_statesStack.empty())
    {
        DEBUG("transition applied");
        _statesStack.top()->Transition(*this, symbol);
    }
}

void AbstractStateMachine::PileUp(const Symbol &symbol, AbstractState *state)
{
    DEBUG("current state is '" << _statesStack.top()->name() << "' -> piling up : new state is '" <<
          state->name() << "' symbol(code='"<<symbol.code<<"',buf='"<<symbol.buf<<"')" );

    _statesStack.push(state);
    _symbolsStack.push(symbol);
}

void AbstractStateMachine::Unexpected(ErrorType type, const Symbol &symbol)
{
    switch(type)
    {
    case LEXICAL_ERROR:
        cerr << "Lexical error (" << _lexer.GetLine() << ":" << _lexer.GetCol() << "): unexpected symbol '" << symbol.buf << "'" << endl;
        break;
    case SYNTAX_ERROR:
        cerr << "Syntax error (" << _lexer.GetLine() << ":" << _lexer.GetCol() << "): expected symbol '" << symbol.buf << "'" << endl;
        break;    
    default:
        break;
    }
}

void AbstractStateMachine::Unexpected(ErrorType type, const string & message)
{
   if(type == WARNING)
   {
        cerr << "Warning :" << message << endl;
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
