#ifndef EXPRESSIONSTATEMACHINE_H
#define EXPRESSIONSTATEMACHINE_H

#include "src/interfaces/abstractstatemachine.h"

/**
 * @brief Automate d'analyse des expressions arithmétiques
 */
class ExpressionStateMachine : public AbstractStateMachine
{
public:
    ~ExpressionStateMachine(){}
    ExpressionStateMachine();
};

#endif // EXPRESSIONSTATEMACHINE_H
