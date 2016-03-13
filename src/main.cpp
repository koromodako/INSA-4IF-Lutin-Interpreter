#include <iostream>
#include <fstream>

#include "config.h"
#include "lexer/lexer.h"
#include "program_statemachine/programstatemachine.h"
#include "optionsManager.h"
#include "types/datamap.h"
#include "types/instructionlist.h"

using namespace std;

#ifndef TEST

void printMan()
{
    cerr << "  Utilisation :" << endl;
    cerr << "    ../lut [-p] [-a] [-e] [-o] source.lt" << endl;
    cerr << "      [-p] affiche le code source reconnu" << endl;
    cerr << "      [-a] analyse le programme de maniere statique" << endl;
    cerr << "      [-e] execute interactivement le programme" << endl;
    cerr << "      [-o] optimise les expressions et instructions" << endl;
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cerr << "Erreur, veuillez specifier des arguments" << endl;
        printMan();
        return 1;
    }

    //Création des structures de stockage
    DataMap dataMap;
    InstructionList instructionList;
    OptionsManager optionsManager(dataMap, instructionList);

    //Traitement des options
    int indexFile = optionsManager.CheckOptions(argc, argv);
    if (indexFile == -1 || indexFile >= argc)
    {
        cerr << "Option inconnue" << endl;
        printMan();
        return -3;
    }

    //Vérification du fichier
    ifstream stream(argv[indexFile]);
    if (!stream.good())
    {
        stream.close();
        cerr << "Erreur a l'ouverture du fichier " << argv[indexFile] << endl;
        return 1;
    }


    // - execution du programme
    // -- construction du lexer
    Lexer lexer(stream);
    // -- construction de l'automate
    ProgramStateMachine programStateMachine(lexer, dataMap, instructionList);
    // -- execution de l'automate
    programStateMachine.Run();
    optionsManager.Execute();

#ifdef PRINT_DEBUG
    cout << endl << "-------------------------- RESULTS --------------------------" << endl;
    cout << endl << "-------------------------- DATAMAP --------------------------" << endl;
    cout << dataMap.Stringify() << endl;
    cout << "-------------------------- INSTRUS --------------------------" << endl;
    cout << instructionList.Stringify() << endl;
#endif

    return 0;
}

#else
#include "src/unit_tests/abstractexpressiontests.h"
#include "src/unit_tests/lexertests.h"
#include "src/unit_tests/instructionlisttests.h"
#include "src/unit_tests/datamaptests.h"
#include "src/unit_tests/expressionfactorytests.h"

int main()
{
    AbstractExpressionTests();
    LexerTests();
    InstructionListTests();
    DataMapTests();
    ExpressionFactoryTests();
}

#endif
