#include "instructionlist.h"
#include "../debug.h"

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

void InstructionList::AppendSymbol(Symbol symbol)
{
    _exprSymbols.push_back(symbol);
    // -- DEBUG ---------------------------------------------------------------------
    DEBUG("AppendSymbol(symbol(code='"<<symbol.code<<"',buf='"<<symbol.buf<<"'))");
    DBG_PRT("internal_symbol_stack = { ");
    for(list<Symbol>::iterator s = _exprSymbols.begin(); s != _exprSymbols.end(); ++s)
    {   if(s != _exprSymbols.begin())
        {   DBG_PRT(", ");
        }
        switch (s->code) {
        case S_NUM:     DBG_PRT("num");         break;
        case S_VAR:     DBG_PRT("var");         break;
        case S_ID:      DBG_PRT("id");          break;
        case S_PLUS:    DBG_PRT("pls");         break;
        case S_MINUS:   DBG_PRT("min");         break;
        case S_MULT:    DBG_PRT("mul");         break;
        case S_DIV:     DBG_PRT("div");         break;
        case S_PO:      DBG_PRT("po");          break;
        case S_PF:      DBG_PRT("pf");          break;
        default:        DBG_PRT("unexpected");  break;
        }
    }
    DBG_PRT(" }" << endl << flush);
    // -- DEBUG ---------------------------------------------------------------------
}

void InstructionList::MergeSymbols()
{
    /// \todo implementer ici
    // -- DEBUG ---------------------------------------------------------------------
    DEBUG("merge required");
    // -- DEBUG ---------------------------------------------------------------------
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
