#include "programstatemachine.h"
#include "states/ps0.h"

ProgramStateMachine::ProgramStateMachine(Lexer &lexer, DataMap &dmap, InstructionList &instructions) :
    AbstractStateMachine(lexer, dmap, instructions)
{
}

bool ProgramStateMachine::Run(AbstractState*)
{
    // initialisation du lexer avec une première lecture
    GetLexer().MoveForward();
    // exécution de la machine à états
    return AbstractStateMachine::Run(new PS0);
}
