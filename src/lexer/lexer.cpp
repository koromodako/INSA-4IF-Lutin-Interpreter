#include "lexer.h"

/*
 *  Dépendance paquet 'libboost-regex-dev'
 */
#include <boost/regex.hpp>

using namespace boost;




static list<pair<regex, Symbol> > REGEX = list<pair<regex, Symbol> >();
#define PUSH(regexp, symbol) REGEX.push_back(make_pair(regex(regexp), symbol))
void init()
{
    PUSH("var",             S_VAR);
    PUSH("lire",            S_READ);
    PUSH("ecrire",          S_WRITE);
    PUSH("const",           S_CONST);
    PUSH("^[a-zA-Z]\\w*$",  S_ID);
    PUSH("\\d+",            S_NUM);
    PUSH("[,]",             S_V);
    PUSH("[;]",             S_PV);
    PUSH("[+]",             S_PLUS);
    PUSH("[-]",             S_MINUS);
    PUSH("[*]",             S_MULT);
    PUSH("[/]",             S_DIV);
    PUSH("[:=]",            S_AFFECT);
    PUSH("[=]",             S_EQ);
    PUSH("[(]",             S_PO);
    PUSH("[)]",             S_PF);
    PUSH("",                S_EOF);
}
regex getRegExp(Symbol symbol) {
    for(list<pair<regex,Symbol> >::iterator p = REGEX.begin(); p != REGEX.end(); ++p)
    {   if(p->second == symbol)
        {   return p->first;
        }
    }
    return regex();
}


Lexer::Lexer(ifstream & stream) :
    _buf(""),
    _latest(S_EOF),
    _stream(stream)
{
}

void Lexer::MoveForward()
{
    // si le buffer est vide
    if(_buf.length() == 0)
    {   // on va chercher la prochaine ligne
        getline(_stream, _buf);
        /// \todo verifier si on n'a pas bitfail levé
    }
    else //sinon
    {   // on supprime la partie lue
        regex_replace(_buf, getRegExp(_latest), "", format_first_only);
    }
}

Symbol Lexer::GetNext(string &val)
{
    for(list<pair<regex, Symbol> >::iterator p = REGEX.begin(); p != REGEX.end(); ++p)
    {   // si la regexp match en debut de chaine
        if(regex_match(_buf, p->first, format_first_only))
        {   // on actualise le latest
            _latest = p->second;
            return _latest;
        }
    }
    return S_LEXER_ERROR;
}
