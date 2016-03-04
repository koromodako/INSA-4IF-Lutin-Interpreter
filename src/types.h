#ifndef TYPES_H
#define TYPES_H

#include <map>
#include <list>
#include <string>

using namespace std;

/**
 * @brief Cette structure décrit une mémoire et les méta-données relatives à cette mémoire.
 */
struct Data {
    bool cst;       ///< la mémoire est constante ou non
    bool set;       ///< la mémoire est écrite ou non
    bool used;      ///< la mémoire est lue ou non
    double value;   ///< la valeur stockée dans la mémoire
    Data(bool _cst = false,
         bool _set = false,
         bool _used = false,
         double _value = -1) :
        cst(_cst),
        set(_set),
        used(_used),
        value(_value)
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

#include "src/interfaces/abstractexpression.h"

class AbstractExpression;

/**
 * @brief Cette structure représente une instruction d'un script lutin
 */
struct Instruction {
    InstructionCode code;       ///< Ce code permet de définir de quel type d'instruction il s'agit (READ,WRITE,AFFECT)
    string identifier;          ///< Utile dans le cas d'une affectation pour savoir quelle variable on affecte dans les cas READ ou AFFECT
    AbstractExpression * expr;  ///< Expression arithmétique de liée à l'instruction si nécessaire
};
// définition du type de liste pour stocker les instructions d'un script lutin
typedef list<Instruction> InstructionList;

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
