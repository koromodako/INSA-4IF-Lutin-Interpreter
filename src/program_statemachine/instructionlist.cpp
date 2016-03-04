#include <iostream>

#include "instructionlist.h"

string InstructionList::Stringify()
{
    cout << "coucou salomé" <<endl;
    string instructions("");
    cout << "coué" <<endl;
    for( InstructionList::iterator i = begin(); i != end(); i++)
	{
        switch (i->code){
			case ICODE_PRINT:
				instructions += "lire ";
                instructions += i->identifier;
				instructions += ";";
				break;
			case ICODE_READ:
				instructions += "ecrire ";
                //instructions += this[i].expr.Stringify();
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
        instructions += "\n";
	}
    return instructions;
}



int Execute(){
	
	
	
	
}
