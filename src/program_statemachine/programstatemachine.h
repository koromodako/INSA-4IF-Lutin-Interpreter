#ifndef PROGRAMSTATEMACHINE_H
#define PROGRAMSTATEMACHINE_H

#include "src/types.h"
#include "src/interfaces/abstractstatemachine.h"

#include <list>

using namespace std;

/**
 * @brief Automate d'analyse de scripts lutin
 */
class ProgramStateMachine : public AbstractStateMachine
{
public:
    ~ProgramStateMachine(){}
    ProgramStateMachine();

private:
    list<Instruction> _instructions;
};

#endif // PROGRAMSTATEMACHINE_H
