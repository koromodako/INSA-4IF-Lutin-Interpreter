#include "instructionlisttests.h"

#include "test_macros.h"
#include "../types/instructionlist.h"
#include "../expression/binaryexpression.h"
#include "../expression/number.h"
#include "../expression/variable.h"


InstructionListTests::InstructionListTests()
{
    stringify_test();
}

void InstructionListTests::stringify_test()
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
