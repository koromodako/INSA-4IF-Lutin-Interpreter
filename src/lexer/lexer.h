#ifndef ABSTRACTLEXER_H
#define ABSTRACTLEXER_H

#include <fstream>

using namespace std;

/**
 * @brief Cette classe représente un lexer quelconque chargé de l'analyse lexicale
 */
class Lexer
{
public:
    Lexer(ifstream & stream);
    ~Lexer();

    void moveForward();

    int getNext();

private:
    string _buf;
    ifstream & _stream;
};

#endif // ABSTRACTLEXER_H
