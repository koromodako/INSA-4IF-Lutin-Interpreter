#ifndef PROGRAMSTATEMACHINE_H
#define PROGRAMSTATEMACHINE_H

#include "../types/types.h"
#include "../interfaces/abstractstatemachine.h"

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

    void Run();

private:

};

#endif // PROGRAMSTATEMACHINE_H
