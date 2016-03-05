#include "programstatemachine.h"

ProgramStateMachine::ProgramStateMachine(Lexer &lexer, DataMap &dmap, InstructionList &instructions) :
    AbstractStateMachine(lexer),
    _instructions(instructions),
    _dmap(dmap)
{

}
