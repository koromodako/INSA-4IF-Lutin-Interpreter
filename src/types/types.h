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
    Instruction(InstructionCode _code = ICODE_READ,
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
    BOP_NOP,        ///< Opérateur inexistant pour la construction des expressions
    BOP_PLUS,       ///< Opérateur d'addition
    BOP_MINUS,      ///< Opérateur de soustraction
    BOP_MULT,       ///< Opérateur de multiplication
    BOP_DIV         ///< Opérateur de division
};

/**
 * @brief Cette cnumération décrit les différents symboles
 * terminaux et non terminaux pouvant être rencontrés dans
 * lors de l'analyse syntaxique
 */
enum SymbolCode {
    // terminaux
    S_LEXER_ERROR   = 0,    ///< symbole terminal non identifiable
    S_CONST         = 101,  ///< mot-clé 'const'
    S_VAR           = 102,  ///< mot-clé 'var'
    S_NUM           = 103,  ///< nombre '\d+'
    S_EQ            = 104,  ///< '='
    S_AFFECT        = 105,  ///< ':='
    S_V             = 106,  ///< ','
    S_PV            = 107,  ///< ';'
    S_READ          = 108,  ///< 'lire'
    S_WRITE         = 109,  ///< 'ecrire'
    S_ID            = 110,  ///< identifiant '\w[\w\d]*'
    S_PO            = 111,  ///< '('
    S_PF            = 112,  ///< ')'
    S_PLUS          = 113,  ///< '+'
    S_MINUS         = 114,  ///< '-'
    S_MULT          = 115,  ///< '*'
    S_DIV           = 116,  ///< '\'
    S_EOF           = 117,  ///< $ (fin du flux)
    // non terminaux
    S_EXP           = 201,  ///< expression arithmetique  ---> appel de l'automate d'expression par l'automate de programme
    S_P             = 202,  ///< programme
    S_D             = 203,  ///< déclaration
    S_LD            = 204,  ///< liste de déclarations
    S_LC            = 205,  ///< liste de constantes
    S_LI            = 206,  ///< liste d'instructions
    S_I             = 207,  ///< instruction
    S_LV            = 208,  ///< liste de variables
    S_A             = 209,  ///< expression
    S_T             = 210,  ///< terme
    S_F             = 211   ///< facteur
};

struct Symbol {
    SymbolCode code;
    string buf;
    Symbol(SymbolCode _code = S_LEXER_ERROR, string _buf = "") :
        code(_code), buf(_buf)
    {}
};

// -- non-terminal symbols
#define SYM_EXP Symbol(S_EXP, "EXP")
#define SYM_P   Symbol(S_P, "P")
#define SYM_D   Symbol(S_D, "D")
#define SYM_LD  Symbol(S_LD, "LD")
#define SYM_LC  Symbol(S_LC, "LC")
#define SYM_LI  Symbol(S_LI, "LI")
#define SYM_LV  Symbol(S_LV, "LV")
#define SYM_I   Symbol(S_I, "I")
#define SYM_A   Symbol(S_A, "A")
#define SYM_T   Symbol(S_T, "T")
#define SYM_F   Symbol(S_F, "F")

#endif // TYPES_H
