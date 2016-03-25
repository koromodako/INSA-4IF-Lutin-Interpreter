#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H

#include <list>
#include <string>

#include "../types/types.h"

/**
 * @brief Cette structure représente une instruction d'un script lutin
 */
struct Instruction {
    InstructionCode code;       ///< Ce code permet de définir de quel type d'instruction il s'agit (lecture, écriture, affectation)
    string identifier;          ///< Utile dans le cas d'une affectation ou d'une lecture pour savoir quelle variable on manipule
    AbstractExpression * expr;  ///< Utile dans le cas d'une affectation ou d'une écriture pour savoir quelle expression on manipule
    Instruction(InstructionCode _code = ICODE_READ,
                string _identifier = "",
                AbstractExpression* _expr = NULL):
        code(_code),
        identifier(_identifier),
        expr(_expr)
    {}
};

/**
 * @brief Classe représentant la liste de toutes les instructions du programme
 */
class InstructionList: public list<Instruction>
{
public:
    /**
     * @brief Constructeur
     */
    InstructionList();
    virtual ~InstructionList();
    /**
     * @brief Ajoute une instruction de lecture sur l'entrée standard
     * @param identifier
     *      Identifiant de la variable dans laquelle la lecture doit être faite
     */
    void StartRead(string & identifier);
    /**
     * @brief Commence l'ajout d'une instruction d'affichage
     */
    void StartPrint();
    /**
     * @brief Commence l'ajout d'une instruction d'affectation
     * @param identifier
     *      Identifiant de la variable à affecter
     */
    void StartSet(string & identifier);
    /**
     * @brief Ajoute un symbole d'expression dans un buffer interne
     * @param symbol
     */
    void AppendSymbol(Symbol symbol);
    /**
     * @brief Construit l'expression à partir de la liste de symboles
     */
    void MergeSymbols();
    /**
     * @brief Termine l'ajout de l'instruction
     */
    void EndInstruction();
    /**
     * @brief Retourne la chaîne de caractères représentant la liste d'instructions
     * @return la structure de donnée sous forme de string à restituer
     */
    string Stringify() const;

    /**
     * @brief Cette méthode vérifie l'intégrité de la structure en réalisant les tests suivants :
     *      + les variables déclarées sont utilisées mais pas initialisées
     *      + les constantes ne sont pas utilisées en partie gauche d'une affectation
     *
     * @return les erreurs trouvées sous forme de chaîne de caractères
     */
    string Test(DataMap &map) const;

private:
    Instruction _currentInstr;
    SymbolList _symbols;
};

#endif // INSTRUCTIIONLIST_H
