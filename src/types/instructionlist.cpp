#include "instructionlist.h"
#include "../debug.h"

#include <iostream>

InstructionList::InstructionList() :
    list<Instruction>(),
    _depth(0),
    _operations(1)
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

    if(symbol.code == S_PO)
    {   _operations[_depth].push_back(Symbol(S_EXP)); // le symbole exp signifie qu'i existe une sous expression
        _depth++; // on incrémente la profondeur
        if(_operations.size() < _depth+1)
        {   _operations.push_back(list<Symbol>()); // on ajoute une liste
        }
    }
    else if(symbol.code == S_PF)
    {   _operations[_depth].push_back(Symbol(S_PF)); // le symbole pf sert de séparateur
        _depth--; // on décrémente la profondeur
    }
    else // dans ce cas on doit recevoir un de PLUS,MINUS,MULT,DIV,ID,NUM
    {   _operations[_depth].push_back(symbol);
    }
}

void InstructionList::MergeSymbols()
{
    // -- DEBUG -----------------------------------------------------
    DEBUG("merge required on structure : ");
    int depth(0);
    for(vector<list<Symbol> >::iterator d = _operations.begin(); d != _operations.end(); ++d)
    {   DBG_PRT("depth " << depth << " : { ");
        for(list<Symbol>::iterator s = d->begin(); s != d->end(); ++s)
        {   if(s != d->begin())
            {   DBG_PRT(", ");
            }
            switch (s->code) {
            case S_EXP:     DBG_PRT("subexp");  break;
            case S_PF:      DBG_PRT("next");    break;
            case S_PLUS:    DBG_PRT("+");       break;
            case S_MINUS:   DBG_PRT("-");       break;
            case S_MULT:    DBG_PRT("*");       break;
            case S_DIV:     DBG_PRT("/");       break;
            case S_ID:      DBG_PRT("id");      break;
            case S_NUM:     DBG_PRT("num");     break;
            default:        DBG_PRT("error");   break;
            }
        }
        DBG_PRT(" }" << endl);
        depth++;
    }
    // -- DEBUG -----------------------------------------------------
    _operations.clear();
    _operations.push_back(list<Symbol>());
    _depth = 0;
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
