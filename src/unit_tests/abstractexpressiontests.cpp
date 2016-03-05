#include "abstractexpressiontests.h"

#include "test_macros.h"
#include "src/expression/variable.h"
#include "src/expression/number.h"
#include "src/expression/binaryexpression.h"

AbstractExpressionTests::AbstractExpressionTests()
{
    stringify_test();
    eval_test();
    simplify_test();
}

void AbstractExpressionTests::stringify_test()
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

void AbstractExpressionTests::eval_test()
{
    cout << "------------------------ AbstractExpression::eval() ------------------------" << endl;
    DataMap dmap;
    dmap.insert(make_pair("a", Data(true, true, false, false, 1)));
    dmap.insert(make_pair("b", Data(true, true, false, false, 1)));
    dmap.insert(make_pair("ab", Data(true, true, false, false, 1)));
    dmap.insert(make_pair("cd", Data(true, true, false, false, 1)));
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

void AbstractExpressionTests::simplify_test()
{
    cout << "------------------------ AbstractExpression::simplify() ------------------------" << endl;
    DataMap dmap;
    dmap.insert(make_pair("cste", Data(true, true, false, false, 2)));
    dmap.insert(make_pair("var", Data(true)));
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
