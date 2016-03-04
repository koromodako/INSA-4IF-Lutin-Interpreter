#include <iostream>

#include "instructionlist.h"

string InstructionList::Stringify()
{
    string instructions("");
    for( InstructionList::iterator i = begin(); i != end(); i++)
	{
        switch (i->code){
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



int Execute(){
	
	
	
	
}
