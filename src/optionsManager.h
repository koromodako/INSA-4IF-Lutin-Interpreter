#ifndef OPTIONS_MANAGER_H
#define OPTIONS_MANAGER_H

#include "types/datamap.h"
#include "types/instructionlist.h"

/**
 * @brief Gestionnaire d'options du programme
 */
class OptionsManager
{
public:
    /**
     * @brief Constructeur
     * @param dataMap
     *      Dictionnaire des mémoires
     * @param instructionList
     *      Liste des instructions
     */
    OptionsManager(DataMap &dataMap, InstructionList &instructionList);
    /**
     * @brief Vérifie quelles options sont requises pour l'exécution
     * @param argc
     *      Nombre d'arguments
     * @param argv
     *      Tableau des arguments
     * @return
     */
    int CheckOptions(int argc, char *argv[]);
    /**
     * @brief Exécute les options demandées sur le fichier lutin passé en paramètre du programme
     */
    void Execute();

private:
    /**
     * @brief Analyse le programme donné de manière statique afin d'en extraire les erreurs
     */
    void analysis() const;

    /**
     * @brief Interprète chacune des instructions du programme de manière interactive
     */
    void execute() const;

    /**
     * @brief Affiche sur la sortie standard la représentation en mémoire du programme
     *        Les éventuelles erreurs sont affichées sur la sortie standard
     */
    void print() const;

    /**
     * @brief Tranforme le programme en mémoire afin de l'optimiser
     */
    void transform();

private:
    DataMap &_dataMap;
    InstructionList &_instructionList;
    bool _display;
    bool _transform;
    bool _execute;
    bool _analysis;
};

#endif // OPTIONS_MANAGER_H
