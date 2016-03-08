#ifndef INSTRUCTIONLIST_H
#define INSTRUCTIONLIST_H

#include <list>
#include <string>

#include "../types.h"
/**
 * @brief Classe representant la liste de toutes les instructions du programme
 */
class InstructionList: public list<Instruction>
{
    /// \todo Implementer la methode d'execution
public:
    InstructionList();
    /**
     * @brief Ajoute une instruction de lecture sur l'entrée standard
     * @param identifier
     *      Identifiant de la variable dans laquelle la lecture doit être faite
     */
    void AppendRead(string & identifier);
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
    ///
    /// \todo Ajouter la méthode pour construire les expressions arithmétiques
    ///
    /**
     * @brief Termine l'ajout d'une instruction quelle qu'elle soit
     */
    void EndInstruction();
    /**
     * @brief Stringify
     * @return la structure de donnée sous forme de string à restituer
     */
    string Stringify() const;
    /**
     * @brief Execute la liste d'instructions
     * @return
     */
    int Execute();



private:
    Instruction _current_instr;
};

#endif // INSTRUCTIIONLIST_H
