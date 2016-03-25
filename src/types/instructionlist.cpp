#include "instructionlist.h"
#include "src/expression/expressionfactory.h"
#include "../debug.h"

#include <sstream>
#include <iostream>

InstructionList::InstructionList() :
    list<Instruction>(),
    _symbols()
{
}

InstructionList::~InstructionList()
{   // Libération de la mémoire réservée pour les expressions dans les instructions
    for(InstructionList::iterator instr = begin(); instr != end(); instr++)
    {   if(instr->expr != NULL)
        {   delete instr->expr;
        }
    }
}

void InstructionList::StartRead(const string & identifier)
{
    _currentInstr = Instruction(ICODE_READ, identifier);
}

void InstructionList::StartPrint()
{
    _currentInstr = Instruction(ICODE_PRINT);
}

void InstructionList::StartSet(const string & identifier)
{
    _currentInstr = Instruction(ICODE_SET, identifier);
}

void InstructionList::AppendSymbol(const Symbol &symbol)
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

string InstructionList::Test(DataMap &dataMap) const
{
    stringstream result;
    for (InstructionList::const_iterator it = begin() ; it != end() ; ++it)
    {
        DataMap::iterator itData = dataMap.find(it->identifier);
        if (it->identifier != "" && itData == dataMap.end())
            itData = dataMap.insert(make_pair(it->identifier, Data())).first;

        //Constante réaffectée - Test 6.5
        if ((it->code == ICODE_SET || it->code == ICODE_READ) && itData->second.cst)
        {
            result << "Error : read-only variable '" << it->identifier << "' is not assignable" << endl;
            itData->second.used = true;
        }
        else if (it->code == ICODE_SET || it->code == ICODE_READ)
            itData->second.set = true;

        if (it->code == ICODE_READ || it->expr == NULL)
            continue;

        //Déclaré, utilisé, mais pas initialisé -- Test 6.1
        set<string> usedVar;
        it->expr->GetUsedVariables(usedVar);
        for (set<string>::iterator itVar = usedVar.begin() ; itVar != usedVar.end() ; ++itVar)
        {
            itData = dataMap.find(*itVar);
            itData->second.used = true;
            if (!itData->second.cst && !itData->second.set)
                result << "Error : '" <<  itData->first << "' used but not initialized" << endl;
        }
    }
    return result.str();
}
