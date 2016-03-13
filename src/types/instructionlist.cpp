#include "instructionlist.h"
#include "src/expression/expressionfactory.h"
#include "../debug.h"

#include <iostream>

InstructionList::InstructionList() :
    list<Instruction>(),
    _symbols()
{
}

void InstructionList::StartRead(string &identifier)
{
    _currentInstr = Instruction(ICODE_READ, identifier);
}

void InstructionList::StartPrint()
{
    _currentInstr = Instruction(ICODE_PRINT);
}

void InstructionList::StartSet(string &identifier)
{
    _currentInstr = Instruction(ICODE_SET, identifier);
}

void InstructionList::AppendSymbol(Symbol symbol)
{
    // -- DEBUG ----------------------------------------------------
    DEBUG("adding symbol(code='"<< symbol.code <<"',buf='"<< symbol.buf <<"')");
    // -- DEBUG ----------------------------------------------------
    _symbols.push_back(symbol);
}

void InstructionList::MergeSymbols()
{
    _currentInstr.expr = ExpressionFactory::MakeExpression(_symbols);
}

void InstructionList::EndInstruction()
{
    push_back(_currentInstr);

    // reset des variables (buffers) internes
    _currentInstr = Instruction();
    _symbols.clear();
}

string InstructionList::Stringify() const
{
    string instructions("");
    for( InstructionList::const_iterator i = begin(); i != end(); i++)
	{
        switch (i->code)
        {
			case ICODE_PRINT:
                instructions += "ecrire ";
                if(i->expr != NULL)
                {   instructions += i->expr->Stringify();
                }
                else
                {   instructions += "NULL_EXPRESSION";
                }
				break;
			case ICODE_READ:
                instructions += "lire ";
                instructions += i->identifier;
				break;
			case ICODE_SET:
                instructions += i->identifier;
				instructions += " := ";
                if(i->expr != NULL)
                {   instructions += i->expr->Stringify();
                }
                else
                {   instructions += "NULL_EXPRESSION";
                }
				break;
			default:
				cout << "Instruction non supportée";
				break;
        }
        instructions += ";\n";
	}
    return instructions;
}
