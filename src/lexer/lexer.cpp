#include "lexer.h"

/*
 *  Dépendance paquet 'libboost-regex-dev'
 */
#include <boost/regex.hpp>

using namespace boost;

static map<string, int> REGEX = map<string, int>();
void init()
{
    //REGEX.insert(make_pair("", ));
}

Lexer::Lexer(ifstream & stream) :
    _buf(""),
    _stream(stream)
{
}

void Lexer::moveForward()
{
    while(_buf.length() == 0)
    {   getline(_stream, _buf, ' ');
        /// \todo verifier si on n'a pas bitfail levé
    }
}

int Lexer::getNext()
{

}
