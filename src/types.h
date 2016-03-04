#ifndef TYPES_H
#define TYPES_H

#include <map>
#include <list>
#include <string>

using namespace std;

/**
 * @brief Cette énumération décrit les différents types d'instructions qui peuvent être rencontrées dans un script lutin
 */
enum InstructionCode {
    ICODE_PRINT,
    ICODE_READ,
    ICODE_SET
};

#include "src/interfaces/abstractexpression.h"

class AbstractExpression;

/**
 * @brief Cette structure représente une instruction d'un script lutin
 */
struct Instruction {
    InstructionCode code;       ///< Ce code permet de définir de quel type d'instruction il s'agit (READ,WRITE,AFFECT)
    string identifier;          ///< Utile dans le cas d'une affectation pour savoir quelle variable on affecte dans les cas READ ou AFFECT
    AbstractExpression * expr;  ///< Expression arithmétique de liée à l'instruction si nécessaire
    Instruction(InstructionCode _code,
                string _identifier = "",
                AbstractExpression* _expr = NULL):
        code(_code),
        identifier(_identifier),
        expr(_expr)
    {}
};

/**
 * @brief Cette énumération définie les différents types d'opérateurs à deux opérandes
 */
enum BinaryOperator {
    BOP_PLUS,       ///< Opérateur d'addition
    BOP_MINUS,      ///< Opérateur de soustraction
    BOP_MULT,       ///< Opérateur de multiplication
    BOP_DIV         ///< Opérateur de division
};


#endif // TYPES_H
