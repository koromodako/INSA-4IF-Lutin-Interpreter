#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H

#include <list>
#include <string>

#include "../types/types.h"
/**
 * @brief Classe representant la liste de toutes les instructions du programme
 */
class InstructionList: public list<Instruction>
{
public:
    InstructionList();
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
     * @brief Termine l'ajout d'une instruction quelle qu'elle soit
     */
    void EndInstruction();
    /**
     * @brief Stringify
     * @return la structure de donnée sous forme de string à restituer
     */
    string Stringify() const;

private:
    Instruction _currentInstr;
    SymbolList _symbols;
};

#endif // INSTRUCTIIONLIST_H
