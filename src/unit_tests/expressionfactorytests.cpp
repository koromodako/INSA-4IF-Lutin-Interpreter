#include "expressionfactorytests.h"
#include "src/expression/expressionfactory.h"
#include "test_macros.h"
#include "src/debug.h"

ExpressionFactoryTests::ExpressionFactoryTests()
{
    build_expr_test();
}

bool operator== (const Symbol & a, const Symbol & b) {
    return (a.code == b.code && a.buf == b.buf);
}

#define ID(id)  Symbol(S_ID, id)
#define PLUS    Symbol(S_PLUS, "+")
#define MINUS   Symbol(S_MINUS, "-")
#define MULT    Symbol(S_MULT, "*")
#define DIV     Symbol(S_DIV, "/")
#define PO      Symbol(S_PO, "(")
#define PF      Symbol(S_PF, ")")

void ExpressionFactoryTests::build_expr_test()
{
    FAILED("not implemented");
}
