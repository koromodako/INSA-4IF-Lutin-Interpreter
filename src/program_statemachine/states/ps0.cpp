#include "ps0.h"

int PS0::transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol.code) {
    case S_CONST:///< mot-clé 'const'
        break;
    case S_VAR:///< mot-clé 'var'
        break;
    case S_NUM:///< nombre '\d+'
        break;
    case S_EQ:///< '='
        break;
    case S_AFFECT:///< ':='
        break;
    case S_V:///< ','
        break;
    case S_PV:///< ';'
        break;
    case S_READ:///< 'lire'
        break;
    case S_WRITE:///< 'ecrire'
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        break;
    case S_EXP:///< expression arithmetique
        break;
    case S_EOF:///< $
        break;
    case S_PO:///< '('
        break;
    case S_PF:///< ')'
        break;
    case S_PLUS:///< '+'
        break;
    case S_MINUS: ///< '-'
        break;
    case S_MULT:///< '*'
        break;
    case S_DIV:///< '\'
        break;
    case S_P:///< programme
        break;
    case S_D:///< déclaration
        break;
    case S_LD:///< liste de déclarations
        break;
    case S_LC:///< liste de constantes
        break;
    case S_LI:///< liste d'instructions
        break;
    case S_I:///< instruction
        break;
    case S_LV:///< liste de variables
        break;
    case S_A:///< expression
        break;
    case S_T:///< terme
        break;
    case S_F:///< facteur
        break;
    default:
        break;
    }
    return -1;
}

PS0::PS0() :
    AbstractPS("PS0")
{

}
