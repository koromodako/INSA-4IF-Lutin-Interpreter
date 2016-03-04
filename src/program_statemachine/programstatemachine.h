#ifndef PROGRAMSTATEMACHINE_H
#define PROGRAMSTATEMACHINE_H

#include "src/types.h"
#include "src/interfaces/abstractstatemachine.h"

#include <list>

using namespace std;

/**
 * @brief Automate d'analyse de scripts lutin
 */
class ProgramStateMachine : public AbstractStateMachine
{
public:
    /**
     * @brief Cette énumération décrit les différents symboles
     * terminaux et non terminaux pouvant être rencontrés dans
     * lors de la l'analyse d'un programme Lutin
     */
    enum Symbol {
        // terminaux
        S_CONST,    ///< mot-clé 'const'
        S_VAR,      ///< mot-clé 'var'
        S_NUM,      ///< nombre '\d+'
        S_EQ,       ///< '='
        S_AFFECT,   ///< ':='
        S_V,        ///< ','
        S_PV,       ///< ';'
        S_READ,     ///< 'lire'
        S_WRITE,    ///< 'ecrire'
        S_ID,       ///< identifiant '\w[\w\d]*'
        S_EXP,      ///< expression arithmetique
        S_EOF,      ///< $ (fin du flux)
        // non terminaux
        S_P,        ///< programme
        S_D,        ///< déclaration
        S_LD,       ///< liste de déclarations
        S_LC,       ///< liste de constantes
        S_LI,       ///< liste d'instructions
        S_I,        ///< instruction
        S_LV        ///< liste de variables
    };

    ~ProgramStateMachine(){}
    ProgramStateMachine();

private:
    list<Instruction> _instructions;
};

#endif // PROGRAMSTATEMACHINE_H
