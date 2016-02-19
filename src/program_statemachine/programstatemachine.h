#ifndef PROGRAMSTATEMACHINE_H
#define PROGRAMSTATEMACHINE_H

#include "src/interfaces/abstractstatemachine.h"

/**
 * @brief Automate d'analyse de scripts lutin
 */
class ProgramStateMachine : public AbstractStateMachine
{
public:
    ~ProgramStateMachine(){}
    ProgramStateMachine();
};

#endif // PROGRAMSTATEMACHINE_H
