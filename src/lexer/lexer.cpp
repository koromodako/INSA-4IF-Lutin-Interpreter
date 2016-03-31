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
}


Lexer::Lexer(ifstream & stream) :
    _buf(""),
    _matched_length(0),
    _stream(stream),
    _line(0),
    _col(0)
{
    init();
}

#define SKIP_INLINE_COMMENT(buffer) \
    if(buffer.length() > 1 && buffer[0] == '/' && buffer[1] == '/') \
    {   buffer.clear();\
    }

#define TRIM_BUF(buffer, col) \
    while(!buffer.empty() && (buffer[0] == ' ' || buffer[0] == '\t'|| buffer[0] == '\n'|| buffer[0] == '\r') ) \
    { \
        buffer.erase(0,1); \
        col++; \
    }

#define SKIP_MULTILINE_COMMENT(stream, buffer, line, col) \
    if(buffer.length() > 1 && buffer[0] == '/' && buffer[1] == '*') \
    {   bool stop(false); \
        for(;;) \
        {   if(buffer.empty()) \
            {   getline(stream, buffer); \
                line++; \
                col = 1; \
            } \
            while(!buffer.empty()) \
            {   if(buffer.length() > 1 && buffer[0] == '*' && buffer[1] == '/') \
                {   stop = true; \
                    buffer.erase(0,2); \
                    col+=2; \
                    break; \
                } \
                buffer.erase(0,1); \
                col++; \
            } \
            if(stop) { break; } \
        } \
    }

void Lexer::AddExpectedSymbol(const string &symbol)
{
    _buf = symbol + _buf;
}

void Lexer::MoveForward()
{   DEBUG("Lexer : MoveForward called.");
    // si le buffer est vide
    if(_buf.empty())
    {   DEBUG("Lexer : buffer is empty, loading next line.");
        // on va chercher la prochaine ligne
        getline(_stream, _buf);
        _line++;
        _col = 1;
        // on trim le buffer
        TRIM_BUF(_buf, _col)
#ifdef SOURCE_COMMENTS_SUPPORT
        SKIP_INLINE_COMMENT(_buf)
        SKIP_MULTILINE_COMMENT(_stream, _buf, _line, _col)
#endif
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
        _col += _matched_length;
        // on trim le buffer
        TRIM_BUF(_buf, _col)
#ifdef SOURCE_COMMENTS_SUPPORT
        SKIP_INLINE_COMMENT(_buf)
        SKIP_MULTILINE_COMMENT(_stream, _buf, _line, _col)
#endif
        if(_buf.empty())
        {   MoveForward();
        }
    }
}

Symbol Lexer::GetNext()
{   DEBUG("Lexer : GetNext called.");
    if(_stream.eof() && _buf.empty())
    {   // test fin de fichier
        return SYM_EOF;
    }
    // on initialise le match avec une chaine vide
    string matched("");
    // on initialise le symbole avec une lexer error
    Symbol symbol;
    // on teste toutes les regex une par une pour trouver celle qui
    for(DictRegexSymbolCode::iterator p = REGEX.begin(); p != REGEX.end(); ++p)
    {
        DEBUG("Lexer : testing regexp '" << p->first.expression() << "' against '" << _buf << "'");
        match_results<string::const_iterator> matches;
        // si la regexp match en debut de chaine
        if(regex_search(_buf, matches, p->first, format_first_only))
        {   size_t currentIndex = _buf.find(matches[0]);
            DEBUG("Lexer : regex '" << p->first.expression() << "' has matched : '" << matches[0] << "' at index '" << currentIndex << "'");
            if(currentIndex == 0)
            {
                DEBUG("Lexer : first to match is '" << matches[0] << "'");
                // maj matched
                matched = matches[0];
                // maj symbole
                symbol.code = p->second;
                // optimisation
                break;
            }
        }
    }
    // si le symbole est différent de lexer error après la boucle précédente alors il existe un match
    if(symbol.code != S_LEXER_ERROR)
    {
        DEBUG("Lexer : finally returning match '" << matched << "'");
        symbol.buf = matched;
        _matched_length = matched.length();
    }
    else
    // sinon c'est une lexer error donc on ne fait rien
    {   for(size_t i = 0 ; i<_buf.length() && _buf[i] != ' ' && _buf[i] != '\n' && _buf[i] != '\r' && _buf[i] != '\t'; i++)
        {
            symbol.buf += _buf[i];
        }
        DEBUG("Lexer : no regex match found. It might be an error in input file");
    }
    return symbol;
}
