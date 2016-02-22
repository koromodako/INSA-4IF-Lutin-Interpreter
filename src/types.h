#ifndef TYPES_H
#define TYPES_H

#include "src/interfaces/abstractexpression.h"

#include <map>
#include <list>
#include <string>


using namespace std;

/**
 * @brief Cette structure décrit une mémoire et les informations relatives à cette mémoire.
 *      cst : si la mémoire est constante ou non
 *      set : si la mémoire est écrite ou non
 *      used : si la mémoire est lue ou non
 *      value : la valeur stockée dans cette mémoire
 */
struct Data {
    bool cst;
    bool set;
    bool used;
    int value;
    Data() :
        cst(false),
        set(false),
        used(false),
        value(-1)
    {}
};
// définition du type de map pour stocker les variables et les constantes du script lutin
typedef map<string, Data> DataMap;

/**
 * @brief Cette énumération décrit les différents types d'instructions qui peuvent être rencontrées dans un script lutin
 */
enum InstructionCode {
    ICODE_PRINT,
    ICODE_READ,
    ICODE_SET
};

class AbstractExpression;

/**
 * @brief Cette structure représente une instruction d'un script lutin
 */
struct Instruction {
    InstructionCode code;
    string identifier;
    AbstractExpression * expr;
};
// définition du type de liste pour stocker les instructions d'un script lutin
typedef list<Instruction> InstructionList;

/**
 * @brief Cette énumération définie les différents types d'opérateurs à deux opérandes
 */
enum BinaryOperator {
    BOP_PLUS,
    BOP_MINUS,
    BOP_MULT,
    BOP_DIV
};


#endif // TYPES_H
