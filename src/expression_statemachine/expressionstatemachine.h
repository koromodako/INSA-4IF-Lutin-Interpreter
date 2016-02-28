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
    /**
     * @brief Cette énumération décrit les différents symboles
     * terminaux et non terminaux pouvant être rencontrés dans
     * lors de la l'analyse d'une expression
     */
    enum Symbol {
        // terminaux
        S_ID,       ///< identifiant '\w[\w\d]*'
        S_NUM,      ///< nombre '\d+'
        S_EOF,      ///< $ (fin du flux)
        S_PO,       ///< '('
        S_PF,       ///< ')'
        S_PLUS,     ///< '+'
        S_MINUS,    ///< '-'
        S_MULT,     ///< '*'
        S_DIV,      ///< '\'
        S_PV,       ///< ';'
        // non terminaux
        S_A,        ///< expression
        S_T,        ///< terme
        S_F         ///< facteur
    };

    ~ExpressionStateMachine(){}
    ExpressionStateMachine();

private:
    AbstractExpression * _expr;
};

#endif // EXPRESSIONSTATEMACHINE_H
