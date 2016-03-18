#include "lexer.h"

#include "src/debug.h"

/*
 *  Dépendance paquet 'libboost-regex-dev'
 */
#include <boost/regex.hpp>

using namespace boost;

typedef list<pair<regex, SymbolCode> > DictRegexSymbolCode;

static DictRegexSymbolCode REGEX = DictRegexSymbolCode();
#define PUSH(regexp, symbol) REGEX.push_back(make_pair(regex(regexp), symbol))
void init()
{
    // l'ordre d'initialisation compte !
    PUSH("var",           S_VAR);
    PUSH("lire",          S_READ);
    PUSH("ecrire",        S_WRITE);
    PUSH("const",         S_CONST);
    PUSH("[a-zA-Z]\\w*",  S_ID); // ne pas placer cette regex avant les quatres premieres
    PUSH("\\d+",          S_NUM);
    PUSH(",",             S_V);
    PUSH(";",             S_PV);
    PUSH("\\+",           S_PLUS);
    PUSH("-",             S_MINUS);
    PUSH("\\*",           S_MULT);
    PUSH("/",             S_DIV);
    PUSH(":=",            S_AFFECT);
    PUSH("=",             S_EQ);
    PUSH("\\(",           S_PO);
    PUSH("\\)",           S_PF);
    //PUSH("",              S_EOF);
}


Lexer::Lexer(ifstream & stream) :
    _buf(""),
    _matched_length(0),
    _stream(stream)
{
    init();
}

#define TRIM_BUF(buffer)  while(buffer[0] == ' ' || buffer[0] == '\t' || buffer[0] == '\n' || buffer[0] == '\r'){buffer.erase(0,1);}

void Lexer::MoveForward()
{   DEBUG("Lexer : MoveForward called.");
    // si le buffer est vide
    if(_buf.empty())
    {   DEBUG("Lexer : buffer is empty, loading next line.");
        // on va chercher la prochaine ligne
        getline(_stream, _buf);
        // on trim le buffer
        TRIM_BUF(_buf);
        // debug
        DEBUG("Lexer : buffer content is : '" << _buf << "'");
        if(_buf.empty() && !_stream.eof())
        {   MoveForward();
        }
    }
    else //sinon
    {   DEBUG("Lexer : deleting latest symbol.");
        // on supprime le dernier token lu
        _buf.erase(0,_matched_length);
        // on trim le buffer
        TRIM_BUF(_buf)
        if(_buf.empty())
        {   MoveForward();
        }
    }
}

Symbol Lexer::GetNext()
{   DEBUG("Lexer : GetNext called.");
    if(_stream.eof())
    {   // test fin de fichier
        return SYM_EOF;
    }
    // on initialise le match avec une chaine vide
    string matched("");
    // on initialise le symbole avec une lexer error
    Symbol symbol;
    // match en premiere sur la ligne contenue dans le buffer
    size_t minMatch = _buf.length();   // on initialise le min a la fin du buffer
    // on teste toutes les regex une par une pour trouver celle qui
    for(DictRegexSymbolCode::iterator p = REGEX.begin(); p != REGEX.end(); ++p)
    {
        DEBUG("Lexer : testing regexp '" << p->first.expression() << "' against '" << _buf << "'");
        //
        match_results<string::const_iterator> matches;
        // si la regexp match en debut de chaine
        if(regex_search(_buf, matches, p->first, format_first_only))
        {   size_t currentIndex = _buf.find_first_of(matches[0]);
            DEBUG("Lexer : regex '" << p->first.expression() << "' has matched : '" << matches[0] << "' at index '" << currentIndex << "' minMatch is '" << minMatch << "'");
            if(currentIndex < minMatch)
            {   DEBUG("Lexer : update min_match ! new matched is '" << matches[0] << "'");
                // maj min match
                minMatch = currentIndex;
                // maj matched
                matched = matches[0];
                // maj symbole
                symbol.code = p->second;
                // optimisation
                if(currentIndex == 0) { break; }
            }
        }
    }
    // si le symbole est différent de lexer error après la boucle précédente c'est qu'on a un match
    if(symbol.code != S_LEXER_ERROR)
    {   DEBUG("Lexer : finally returning match '" << matched << "'");
        symbol.buf = matched;
        _matched_length = matched.length();
    }
    else
    {   // sinon c'est une lexer error donc on ne fait rien
        DEBUG("Lexer : no regex match found. It might be an error in input file");
    }
    return symbol;
}
