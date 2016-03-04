#include <iostream>
#include <fstream>

#include "lexer/lexer.h"
#include "program_statemachine/programstatemachine.h"
#include "optionsManager.h"
#include "program_statemachine/datamap.h"
#include "program_statemachine/instructionlist.h"

using namespace std;

#define TEST

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
            {   cout << "test - " << i << " - FAILED !" << endl;
                cout << "expected output : " << *expect << endl;
                cout << "output : " << (*expr)->Stringify() << endl;
            }
            else
            {   cout << "test - " << i << " - SUCCESS !" << endl;
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
            {   cout << "test - " << i << " - FAILED !" << endl;
            }
            if(*expect != val)
            {   cout << "test - " << i << " - FAILED !" << endl;
                cout << "expected output : " << *expect << endl;
                cout << "output : " << (*expr)->Eval(dmap, ok) << endl;
            }
            else
            {   cout << "test - " << i << " - SUCCESS !" << endl;
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

    // execute
    if(expected.size() == expressions.size())
    {
        list<string>::iterator expect = expected.begin();
        list<AbstractExpression*>::iterator expr = expressions.begin();
        int i(0);
        while (expect != expected.end() && expr != expressions.end()) {
            bool ok = false;
            if(!ok)
            {   cout << "test - " << i << " - FAILED !" << endl;
            }
            if(*expect != (*expr)->Stringify())
            {   cout << "test - " << i << " - FAILED !" << endl;
                cout << "expected output : " << *expect << endl;
                cout << "output : " << (*expr)->Stringify() << endl;
            }
            else
            {   cout << "test - " << i << " - SUCCESS !" << endl;
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
    cout << "non implementé" << endl;
    cout << "-------------------------------------- done -------------------------------------" << endl;
}

void instruction_stringify_test()
{
    cout << "coué" <<endl;
    /// \todo modifier une fois le sringify des expressions implementé
    InstructionList instructions;
    instructions.push_back(Instruction(ICODE_READ, "b", NULL));
    instructions.push_back(Instruction(ICODE_SET, "a", NULL));
    instructions.push_back(Instruction(ICODE_PRINT, NULL, NULL));

    cout << instructions.Stringify() <<endl;

}

void datamap_stringify_test()
{
    DataMap datamap;
    datamap.insert(make_pair("a", Data(false, false, false)));
    datamap.insert(make_pair("b", Data(false, false, false)));
    datamap.insert(make_pair("c", Data(true, false, false, 5)));

    cout << datamap.Stringify() <<endl;
}

#endif
