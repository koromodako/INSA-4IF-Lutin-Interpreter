#include <iostream>
#include <fstream>

#include "config.h"
#include "lexer/lexer.h"
#include "program_statemachine/programstatemachine.h"
#include "optionsManager.h"
#include "program_statemachine/datamap.h"
#include "program_statemachine/instructionlist.h"

using namespace std;

#ifndef TEST

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Aucun fichier spécifié" << endl;
        cerr << "Syntaxe d'appel : ./Lutin nomFichier.lt [-p] [-o] [-a] [-e]" << endl;
        return -1;
    }

    ifstream stream(argv[1]);

    //Vérification du fichier
    if (!stream.good())
    {
        stream.close();
        cerr << "Impossible d'ouvrir le fichier : " << argv[1] << endl;
        cerr << "Syntaxe d'appel : ./Lutin nomFichier.lt [-p] [-o] [-a] [-e]" << endl;
        return -2;
    }

    //Création des structures de stockage
    DataMap dataMap;
    InstructionList instructionList;
    OptionsManager optionsManager(dataMap, instructionList);
    //Traitement des options
    if (!optionsManager.CheckOption(argc, argv))
    {
        cerr << "Option inconnue" << endl;
        cerr << "Syntaxe d'appel : ./Lutin nomFichier.lt [-p] [-o] [-a] [-e]" << endl;
        return -3;
    }

    // - execution du programme
    // -- construction du lexer
    Lexer lexer(stream);
    // -- construction de l'automate
    ProgramStateMachine programStateMachine(lexer, dataMap, instructionList);

    return 0;
}

#else
#include "src/unit_tests/abstractexpressiontests.h"
#include "src/unit_tests/lexertests.h"
#include "src/unit_tests/instructionlisttests.h"
#include "src/unit_tests/datamaptests.h"

int main()
{
    AbstractExpressionTests();
    LexerTests();
    InstructionListTests();
    DataMapTests();
}

#endif
