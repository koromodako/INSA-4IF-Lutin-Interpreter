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
    Symbol symbol;
    lexer.MoveForward(); // commence à lire en placant la tete de lecture au debut du flux
    symbol = lexer.GetNext();
    while(symbol.code != S_EOF)
    {   if(symbol.code == S_LEXER_ERROR)
        {   PRINT("Lexer error encountered...");
            break;
        }
        // on récupère les valeurs
        symbols.push_back(symbol);
        // on déplace la tête de lecture
        lexer.MoveForward();
        // on lit le prochain symbole
        symbol = lexer.GetNext();
    }
    symbols.push_back(symbol);
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
#define PUSH_SYM(symbolcode, value) expectedSymbols.push_back(Symbol(symbolcode, value));
    // ligne 1
    PUSH_SYM(S_VAR,"var");PUSH_SYM(S_ID,"a");PUSH_SYM(S_V,",");PUSH_SYM(S_ID,"b");PUSH_SYM(S_PV,";");
    // ligne 2
    PUSH_SYM(S_CONST,"const");PUSH_SYM(S_ID,"c");PUSH_SYM(S_EQ,"=");PUSH_SYM(S_NUM,"4");PUSH_SYM(S_PV,";");
    // ligne 3
    PUSH_SYM(S_CONST,"const");PUSH_SYM(S_ID,"d");PUSH_SYM(S_EQ,"=");PUSH_SYM(S_NUM,"6");PUSH_SYM(S_PV,";");
    // ligne 4
    PUSH_SYM(S_VAR,"var");PUSH_SYM(S_ID,"e");PUSH_SYM(S_PV,";");
    // ligne 5
    PUSH_SYM(S_ID,"a");PUSH_SYM(S_AFFECT,":=");PUSH_SYM(S_PO,"(");PUSH_SYM(S_ID,"c");PUSH_SYM(S_PLUS,"+");PUSH_SYM(S_ID,"d");PUSH_SYM(S_PF,")");PUSH_SYM(S_MULT,"*");PUSH_SYM(S_NUM,"3");PUSH_SYM(S_MINUS,"-");PUSH_SYM(S_NUM,"5");PUSH_SYM(S_PV,";");
    // ligne 6
    PUSH_SYM(S_READ,"lire");PUSH_SYM(S_ID,"b");PUSH_SYM(S_PV,";");
    // ligne 7
    PUSH_SYM(S_WRITE,"ecrire");PUSH_SYM(S_ID,"a");PUSH_SYM(S_MULT,"*");PUSH_SYM(S_ID,"b");PUSH_SYM(S_PV,";");
    // ligne 8
    PUSH_SYM(S_ID,"e");PUSH_SYM(S_AFFECT,":=");PUSH_SYM(S_ID,"b");PUSH_SYM(S_PLUS,"+");PUSH_SYM(S_ID,"d");PUSH_SYM(S_PV,";");
    // ligne 9
    PUSH_SYM(S_WRITE,"ecrire");PUSH_SYM(S_ID,"e");PUSH_SYM(S_PV,";");
    // eof
    PUSH_SYM(S_EOF,"");

    // verification de l'adequation des quatres tableaux
    // -- on vérifie d'abord la taille
    if(symbols.size() != expectedSymbols.size())
    {   FAILED(0);
        PRINT("Les tailles des tableaux ne correspondent pas !");
        PRINT("symbols.size() = " << symbols.size());
        PRINT("expectedSymbols.size() = " << expectedSymbols.size());
    }
    else
    {   list<Symbol>::iterator realSymbol = symbols.begin(), expectedSymbol = expectedSymbols.begin();
        // ici on peut tester que sur un itérateur car on sait que tous les tableaux font la meme taille
        int iter(1);
        bool failed(false);
        while(realSymbol != symbols.end())
        {   // tests de correspondance
            if(realSymbol->code != expectedSymbol->code)
            {   FAILED(iter);
                PRINT("real code = '" << realSymbol->code << "'");
                PRINT("expected code = '" << expectedSymbol->code << "'");
                failed = true;
                break; // sortie du while
            }
            else if(realSymbol->buf != expectedSymbol->buf)
            {   FAILED(iter);
                PRINT("real buf = '" << realSymbol->buf << "'");
                PRINT("expected buf = '" << expectedSymbol->buf << "'");
                failed = true;
                break; // sortie du while
            }
            // incrément des itérateurs
            realSymbol++; expectedSymbol++;
            iter++;
        }
        if(!failed)
        {   SUCCESS(0);
        }
    }


    cout << "-------------------------------------- done -------------------------------------" << endl;
}
