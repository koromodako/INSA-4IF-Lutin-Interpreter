#include "instructionlist.h"
#include <iostream>

InstructionList::InstructionList() :
    list<Instruction>()
{
}

void InstructionList::AppendRead(string &identifier)
{
    _currentInstr = Instruction(ICODE_READ, identifier);
    EndInstruction();
}

void InstructionList::StartPrint()
{
    _currentInstr = Instruction(ICODE_PRINT);
}

void InstructionList::StartSet(string &identifier)
{
    _currentInstr = Instruction(ICODE_SET, identifier);
}

void InstructionList::EndInstruction()
{
    push_back(_currentInstr);
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
                instructions += i->expr->Stringify();
				break;
			case ICODE_READ:
                instructions += "lire ";
                instructions += i->identifier;
				break;
			case ICODE_SET:
                instructions += i->identifier;
				instructions += " := ";
                instructions += i->expr->Stringify();
				break;
			default:
				cout << "Instruction non supportée";
				break;
        }
        instructions += ";\n";
	}
    return instructions;
}
