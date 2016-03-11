#include "lexertests.h"

#include "test_macros.h"
#include "src/lexer/lexer.h"

LexerTests::LexerTests()
{
    nominal_test();
}

void LexerTests::nominal_test()
{
    cout << "-------------------------------------- Lexer ------------------------------------" << endl;

    ifstream ifs("../../tests/files/correct.lt");
    //Vérification du fichier
    if (!ifs.good())
    {
        ifs.close();
        FAILED(0);
        PRINT("Failed to open file...");
        return;
    }
    Lexer lexer(ifs);
    list<Symbol> symbols;
    list<string> values;
    Symbol symbol;
    string value;
    lexer.MoveForward(); // commence à lire en placant la tete de lecture au debut du flux
    while((symbol = lexer.GetNext(value)) != S_EOF)
    {   if(symbol == S_LEXER_ERROR)
        {   PRINT("Lexer error encountered...");
            break;
        }
        // on récupère les valeurs
        symbols.push_back(symbol);
        values.push_back(value);
        // on déplace la tête de lecture
        lexer.MoveForward();
    }
    symbols.push_back(symbol);
    values.push_back(value);
    /*
     * Programme testé : correct.lt
     *
     * 1. var a,b;
     * 2. const c = 4;
     * 3. const d = 6;
     * 4. var e;
     * 5. a := (c+d)*3-5;
     * 6. lire b;
     * 7. ecrire a*b;
     * 8. e := b+d;
     * 9. ecrire e;
     */
    list<Symbol> expectedSymbols;
    list<string> expectedValues;
#define PUSH_SYM(symbol) expectedSymbols.push_back(symbol)
#define PUSH_VAL(value) expectedValues.push_back(value)
    // ligne 1
    PUSH_SYM(S_VAR);PUSH_SYM(S_ID);PUSH_SYM(S_V);PUSH_SYM(S_ID);PUSH_SYM(S_PV);
    PUSH_VAL("var");PUSH_VAL("a");PUSH_VAL(",");PUSH_VAL("b");PUSH_VAL(";");
    // ligne 2
    PUSH_SYM(S_CONST);PUSH_SYM(S_ID);PUSH_SYM(S_EQ);PUSH_SYM(S_NUM);PUSH_SYM(S_PV);
    PUSH_VAL("const");PUSH_VAL("c");PUSH_VAL("=");PUSH_VAL("4");PUSH_VAL(";");
    // ligne 3
    PUSH_SYM(S_CONST);PUSH_SYM(S_ID);PUSH_SYM(S_EQ);PUSH_SYM(S_NUM);PUSH_SYM(S_PV);
    PUSH_VAL("const");PUSH_VAL("d");PUSH_VAL("=");PUSH_VAL("6");PUSH_VAL(";");
    // ligne 4
    PUSH_SYM(S_VAR);PUSH_SYM(S_ID);PUSH_SYM(S_PV);
    PUSH_VAL("var");PUSH_VAL("e");PUSH_VAL(";");
    // ligne 5
    PUSH_SYM(S_ID);PUSH_SYM(S_AFFECT);PUSH_SYM(S_PO);PUSH_SYM(S_ID);PUSH_SYM(S_PLUS);PUSH_SYM(S_ID);PUSH_SYM(S_PF);PUSH_SYM(S_MULT);PUSH_SYM(S_NUM);PUSH_SYM(S_MINUS);PUSH_SYM(S_NUM);PUSH_SYM(S_PV);
    PUSH_VAL("a");PUSH_VAL(":=");PUSH_VAL("(");PUSH_VAL("c");PUSH_VAL("+");PUSH_VAL("d");PUSH_VAL(")");PUSH_VAL("*");PUSH_VAL("3");PUSH_VAL("-");PUSH_VAL("5");PUSH_VAL(";");
    // ligne 6
    PUSH_SYM(S_READ);PUSH_SYM(S_ID);PUSH_SYM(S_PV);
    PUSH_VAL("lire");PUSH_VAL("b");PUSH_VAL(";");
    // ligne 7
    PUSH_SYM(S_WRITE);PUSH_SYM(S_ID);PUSH_SYM(S_MULT);PUSH_SYM(S_ID);PUSH_SYM(S_PV);
    PUSH_VAL("ecrire");PUSH_VAL("a");PUSH_VAL("*");PUSH_VAL("b");PUSH_VAL(";");
    // ligne 8
    PUSH_SYM(S_ID);PUSH_SYM(S_AFFECT);PUSH_SYM(S_ID);PUSH_SYM(S_PLUS);PUSH_SYM(S_ID);PUSH_SYM(S_PV);
    PUSH_VAL("e");PUSH_VAL(":=");PUSH_VAL("b");PUSH_VAL("+");PUSH_VAL("d");PUSH_VAL(";");
    // ligne 9
    PUSH_SYM(S_WRITE);PUSH_SYM(S_ID);PUSH_SYM(S_PV);
    PUSH_VAL("ecrire");PUSH_VAL("e");PUSH_VAL(";");
    // eof
    PUSH_SYM(S_EOF);
    PUSH_VAL("");

    // verification de l'adequation des quatres tableaux
    // -- on vérifie d'abord la taille
    if(values.size() != symbols.size() || values.size() != expectedSymbols.size() || values.size() != expectedValues.size())
    {   FAILED(0);
        PRINT("Les tailles des tableaux ne correspondent pas !");
        PRINT("values.size() = " << values.size());
        PRINT("symbols.size() = " << symbols.size());
        PRINT("expectedValues.size() = " << expectedValues.size());
        PRINT("expectedSymbols.size() = " << expectedSymbols.size());
    }
    else
    {   list<Symbol>::iterator realSymbol = symbols.begin(), expectedSymbol = expectedSymbols.begin();
        list<string>::iterator realValue = values.begin(), expectedValue = expectedValues.begin();
        // ici on peut tester que sur un itérateur car on sait que tous les tableaux font la meme taille
        int iter(1);
        bool failed(false);
        while(realValue != values.end())
        {   // tests de correspondance
            if(*realSymbol != *expectedSymbol)
            {   FAILED(iter);
                PRINT("realSymbol = '" << *realSymbol << "'");
                PRINT("expectedSymbol = '" << *expectedSymbol << "'");
                failed = true;
                break; // sortie du while
            }
            else if(*realValue != *expectedValue)
            {   FAILED(iter);
                PRINT("realValue = '" << *realValue << "'");
                PRINT("expectedValue = '" << *expectedValue << "'");
                failed = true;
                break; // sortie du while
            }
            // incrément des itérateurs
            realValue++; expectedValue++;
            realSymbol++; expectedSymbol++;
            iter++;
        }
        if(!failed)
        {   SUCCESS(0);
        }
    }


    cout << "-------------------------------------- done -------------------------------------" << endl;
}
