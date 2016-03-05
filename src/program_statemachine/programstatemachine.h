#ifndef PROGRAMSTATEMACHINE_H
#define PROGRAMSTATEMACHINE_H

#include "src/types.h"
#include "src/interfaces/abstractstatemachine.h"
#include "src/program_statemachine/instructionlist.h"

#include <list>

using namespace std;

/**
 * @brief Automate d'analyse de scripts lutin
 */
class ProgramStateMachine : public AbstractStateMachine
{
public:
    ~ProgramStateMachine(){}
    ProgramStateMachine(Lexer & lexer, DataMap & dmap, InstructionList & instructions);

private:
    InstructionList & _instructions;
    DataMap & _dmap; // cet automate doit remplir cette structure avec les déclarations de variables et constantes
};

#endif // PROGRAMSTATEMACHINE_H
