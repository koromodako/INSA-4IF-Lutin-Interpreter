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
    OptionsManager(DataMap &dataMap, InstructionList &instructionList);

    int CheckOptions(int argc, char *argv[]);
    void Execute();

private:
    /**
     * @brief Analyse le programme donné de manière statique afin d'en extraire les erreurs.
     */
    void analysis() const;

    /**
     * @brief Interprete chacune des instructions du programme de manière intéractive.
     */
    void execute() const;

    /**
     * @brief Affiche sur la sortie standard la représentation en mémoire du programme.
     *        Les éventuelles erreurs sont affichées sur la sortie standard
     */
    void print() const;

    /**
     * @brief Tranforme le programme en mémoire afin de l'optimiser.
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
