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

    //Execution du programme
    ProgramStateMachine programStateMachine/*(stream, dataMap, instructionMap)*/;

    return 0;
}

#else

#include "expression/variable.h"
#include "expression/number.h"
#include "expression/binaryexpression.h"
#include "program_statemachine/instructionlist.h"
#include "program_statemachine/datamap.h"

void expr_stringify_test();
void expr_eval_test();
void expr_simplify_test();
void lexer_test();
void instruction_stringify_test();
void datamap_stringify_test();

int main()
{
    expr_stringify_test();
    expr_eval_test();
    expr_simplify_test();
    lexer_test();
    instruction_stringify_test();
    datamap_stringify_test();
}

#define FAILED(info)   cerr << "test - " << info << " - FAILED !" << endl
#define SUCCESS(info)  cout << "test - " << info << " - SUCCESS !" << endl
#define PRINT(msg)      cerr << msg << endl

void expr_stringify_test()
{
    cout << "------------------------ AbstractExpression::stringify() ------------------------" << endl;
    list<string> expected;
    list<AbstractExpression*> expressions;

    // creation des arbres de calculs
    expressions.push_back(new Number(1));
    expected.push_back("1");
    expressions.push_back(new Variable("variable"));
    expected.push_back("variable");
    expressions.push_back(new BinaryExpression(BOP_PLUS, new Number(1), new Number(1)));
    expected.push_back("(1+1)");
    expressions.push_back(new BinaryExpression(BOP_MINUS, new Number(1), new Variable("a")));
    expected.push_back("(1-a)");
    expressions.push_back(new BinaryExpression(BOP_MULT, new Variable("ab"), new Variable("cd")));
    expected.push_back("(ab*cd)");
    expressions.push_back(new BinaryExpression(BOP_DIV, new Number(1), new BinaryExpression(BOP_PLUS, new Variable("a"), new Variable("b"))));
    expected.push_back("(1/(a+b))");


    // execute
    if(expected.size() == expressions.size())
    {
        list<string>::iterator expect = expected.begin();
        list<AbstractExpression*>::iterator expr = expressions.begin();
        int i(0);
        while (expect != expected.end() && expr != expressions.end()) {
            if(*expect != (*expr)->Stringify())
            {   FAILED(i);
                PRINT("expected output : " << *expect);
                PRINT("output : " << (*expr)->Stringify());
            }
            else
            {   SUCCESS(i);
            }
            // move iterators
            expect++;
            expr++;
            i++;
        }
    }
    else
    {
        cout << "Expected strings count doesn't match expressions count !" << endl;
    }


    // destructions
    for(list<AbstractExpression*>::iterator e = expressions.begin(); e != expressions.end(); e++)
    {   delete (*e);
    }

    cout << "-------------------------------------- done -------------------------------------" << endl;
}

void expr_eval_test()
{
    cout << "------------------------ AbstractExpression::eval() ------------------------" << endl;
    DataMap dmap;
    dmap.insert(make_pair("a", Data(true, false, false, 1)));
    dmap.insert(make_pair("b", Data(true, false, false, 1)));
    dmap.insert(make_pair("ab", Data(true, false, false, 1)));
    dmap.insert(make_pair("cd", Data(true, false, false, 1)));
    list<double> expected;
    list<AbstractExpression*> expressions;

    // creation des arbres de calculs
    expressions.push_back(new Number(1));
    expected.push_back(1);
    expressions.push_back(new Variable("a"));
    expected.push_back(1);
    expressions.push_back(new BinaryExpression(BOP_PLUS, new Number(1), new Number(1)));
    expected.push_back(2);
    expressions.push_back(new BinaryExpression(BOP_MINUS, new Number(1), new Variable("a")));
    expected.push_back(0);
    expressions.push_back(new BinaryExpression(BOP_MULT, new Variable("ab"), new Variable("cd")));
    expected.push_back(1);
    expressions.push_back(new BinaryExpression(BOP_DIV, new Number(1), new BinaryExpression(BOP_PLUS, new Variable("a"), new Variable("b"))));
    expected.push_back(0.5);


    // execute
    if(expected.size() == expressions.size())
    {
        list<double>::iterator expect = expected.begin();
        list<AbstractExpression*>::iterator expr = expressions.begin();
        int i(0);
        while (expect != expected.end() && expr != expressions.end()) {
            bool ok = false;
            double val = (*expr)->Eval(dmap, ok);
            if(!ok)
            {   FAILED(i);
            }
            if(*expect != val)
            {   FAILED(i);
                PRINT("expected output : " << *expect);
                PRINT("output : " << (*expr)->Eval(dmap, ok));
            }
            else
            {   SUCCESS(i);
            }
            // move iterators
            expect++;
            expr++;
            i++;
        }
    }
    else
    {
        cout << "Expected strings count doesn't match expressions count !" << endl;
    }


    // destructions
    for(list<AbstractExpression*>::iterator e = expressions.begin(); e != expressions.end(); e++)
    {   delete (*e);
    }

    cout << "-------------------------------------- done -------------------------------------" << endl;
}

void expr_simplify_test()
{
    cout << "------------------------ AbstractExpression::simplify() ------------------------" << endl;
    DataMap dmap;
    dmap.insert(make_pair("cste", Data(true, false, false, 2)));
    dmap.insert(make_pair("var", Data()));
    list<string> expected;
    list<AbstractExpression*> expressions;

    // creation des arbres de calculs
    expected.push_back("var");
    expressions.push_back(new BinaryExpression(BOP_MULT, new Number(1), new Variable("var"))); // 1*var
    expected.push_back("var");
    expressions.push_back(new BinaryExpression(BOP_PLUS, new Number(0), new Variable("var"))); // 0+var
    expected.push_back("2");
    expressions.push_back(new Variable("cste")); // cste
    expected.push_back("10");
    expressions.push_back(new BinaryExpression(BOP_MULT, new Number(2), new Number(5))); // 2*5
    expected.push_back("(var*var)");
    expressions.push_back(new BinaryExpression(BOP_MULT, new Variable("var"), new Variable("var"))); // var*var

    // execute
    if(expected.size() == expressions.size())
    {
        list<string>::iterator expect = expected.begin();
        list<AbstractExpression*>::iterator expr = expressions.begin();
        int i(0);

        while (expect != expected.end() && expr != expressions.end()) {
            bool ok = false;
            AbstractExpression * simplified = (*expr)->Simplify(dmap, ok);
            if(!ok)
            {   FAILED(i);
                PRINT("simplify failed !");
            }
            else
            {   if(simplified != NULL)
                {   if(*expect != simplified->Stringify())
                    {   FAILED(i);
                        PRINT("expected output : " << *expect);
                        PRINT("output : " << simplified->Stringify());
                    }
                    else
                    {   SUCCESS(i); // fully simplified
                    }
                    // free memory allocated for simplified expression tree
                    delete simplified;
                }
                else
                {   SUCCESS(i); // not simplified but successfull cause it can't be simplified
                }
            }
            // move iterators
            expect++;
            expr++;
            i++;
        }
    }
    else
    {
        cout << "Expected strings count doesn't match expressions count !" << endl;
    }


    // destructions
    for(list<AbstractExpression*>::iterator e = expressions.begin(); e != expressions.end(); e++)
    {   delete (*e);
    }

    cout << "-------------------------------------- done -------------------------------------" << endl;
}

void lexer_test()
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

void instruction_stringify_test()
{
    cout << "------------------------ InstructionList::Stringify() -----------------------------" << endl;
    string test("lire b;\na := (1+1);\necrire a;\n");
    InstructionList instructions;
    instructions.push_back(Instruction(ICODE_READ, "b", NULL));
    instructions.push_back(Instruction(ICODE_SET, "a", new BinaryExpression(BOP_PLUS, new Number(1), new Number(1))));
    instructions.push_back(Instruction(ICODE_PRINT, "", new Variable("a")));
    string stringify = instructions.Stringify();
    if(test != stringify)
    {   FAILED(0);
        PRINT("expected :" << test);
        PRINT("received :"<< stringify);
    }
    else
    {   SUCCESS(0);
    }
    cout << "------------------------------------- done ------------------------------------" << endl;

}

void datamap_stringify_test()
{
    cout << "------------------------ DataMap::Stringify() -----------------------------" << endl;
    string test("var a;\nvar b;\nconst c=5;\n");
    DataMap datamap;
    datamap.insert(make_pair("a", Data(false, false, false)));
    datamap.insert(make_pair("b", Data(false, false, false)));
    datamap.insert(make_pair("c", Data(true, false, false, 5)));
    string stringify = datamap.Stringify();
    if(test != stringify)
    {   FAILED(0);
        PRINT("expected :" << test);
        PRINT("received :"<< stringify);
    }
    else
    {   SUCCESS(0);
    }
    cout << "-------------------------------------- done -----------------------------------" << endl;

}

#endif
