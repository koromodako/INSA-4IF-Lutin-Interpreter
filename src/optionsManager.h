#ifndef OPTIONS_MANAGER_H
#define OPTIONS_MANAGER_H

#include "src/program_statemachine/datamap.h"
#include "src/program_statemachine/instructionlist.h"

/**
 * @brief Gestionnaire d'options du programme
 */
class OptionsManager
{
public:
    OptionsManager(DataMap &dataMap, InstructionList &instructionList);

    bool CheckOption(int argc, char *argv[]);
    void Execute();

private:
    /**
     * @brief Analyse le programme donné de manière statique afin d'en extraire les erreurs.
     */
    void analysis();

    /**
     * @brief Interprete chacune des instructions du programme de manière intéractive.
     */
    void execute();

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
