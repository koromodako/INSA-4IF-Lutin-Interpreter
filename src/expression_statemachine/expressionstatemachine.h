#ifndef EXPRESSIONSTATEMACHINE_H
#define EXPRESSIONSTATEMACHINE_H

#include "src/interfaces/abstractstatemachine.h"
#include "src/interfaces/abstractexpression.h"

/**
 * @brief Automate d'analyse des expressions arithmétiques
 */
class ExpressionStateMachine : public AbstractStateMachine
{
public:
    ~ExpressionStateMachine(){}
    ExpressionStateMachine();

private:
    AbstractExpression * _expr;
};

#endif // EXPRESSIONSTATEMACHINE_H
