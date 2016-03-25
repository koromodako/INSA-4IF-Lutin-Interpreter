#ifndef TYPES_H
#define TYPES_H

#include <map>
#include <list>
#include <stack>
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
 * @brief Cette énumération définit les différents types d'opérations binaires
 */
enum BinaryOperator {
    BOP_PLUS,       ///< Opérateur d'addition
    BOP_MINUS,      ///< Opérateur de soustraction
    BOP_MULT,       ///< Opérateur de multiplication
    BOP_DIV         ///< Opérateur de division
};

/**
 * @brief Cette énumération décrit les différents symboles
 * terminaux et non terminaux pouvant être rencontrés lors
 * de l'analyse syntaxique
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
    S_EXP           = 201,  ///< expression arithmétique  ---> appel de l'automate d'expression par l'automate de programme
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

/**
 * @brief Cette structure définit un symbole par son code et sa chaîne de caractères
 */
struct Symbol {
    SymbolCode code;
    string buf;
    Symbol(SymbolCode _code = S_LEXER_ERROR, string _buf = "") :
        code(_code), buf(_buf)
    {}
};
// ------------------------------- types
typedef stack<Symbol> SymbolStack;
typedef list<Symbol> SymbolList;

// ------------------------------- macros
#define SYM_EXP         Symbol(S_EXP, "EXP")
#define SYM_P           Symbol(S_P, "P")
#define SYM_D           Symbol(S_D, "D")
#define SYM_LD          Symbol(S_LD, "LD")
#define SYM_LC          Symbol(S_LC, "LC")
#define SYM_LI          Symbol(S_LI, "LI")
#define SYM_LV          Symbol(S_LV, "LV")
#define SYM_I           Symbol(S_I, "I")
#define SYM_A           Symbol(S_A, "A")
#define SYM_T           Symbol(S_T, "T")
#define SYM_F           Symbol(S_F, "F")
#define SYM_EOF         Symbol(S_EOF, "EOF")

#define SYM_CONST       Symbol(S_CONST, "const")
#define SYM_VAR         Symbol(S_VAR, "var")
#define SYM_NUM         Symbol(S_NUM, "numeric value")
#define SYM_EQ          Symbol(S_EQ, "=")
#define SYM_AFFECT      Symbol(S_AFFECT, ":=")
#define SYM_V           Symbol(S_V, ",")
#define SYM_PV          Symbol(S_PV, ";")
#define SYM_READ        Symbol(S_READ, "lire")
#define SYM_WRITE       Symbol(S_WRITE, "ecrire")
#define SYM_ID          Symbol(S_ID, "identifier")
#define SYM_PO          Symbol(S_PO, "(")
#define SYM_PF          Symbol(S_PF, ")")
#define SYM_PLUS        Symbol(S_PLUS, "+")
#define SYM_MINUS       Symbol(S_MINUS, "-")
#define SYM_MULT        Symbol(S_MULT, "*")
#define SYM_DIV         Symbol(S_DIV, "/")

#endif // TYPES_H
