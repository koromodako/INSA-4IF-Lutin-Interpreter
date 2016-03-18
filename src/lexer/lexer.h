#ifndef ABSTRACTLEXER_H
#define ABSTRACTLEXER_H

#include "../types/types.h"

#include <fstream>

using namespace std;

/**
 * @brief Cette classe représente un lexer quelconque chargé de l'analyse lexicale
 */
class Lexer
{
public:
    Lexer(ifstream & stream);
    ~Lexer(){}
    /**
     * @brief Déplace la tête de lecture
     */
    void MoveForward();
    /**
     * @brief Retourne le symbole actuellement sous la tête de lecture
     * @return
     */
    Symbol GetNext();

private:
    string _buf;
    size_t _matched_length;
    ifstream & _stream;
};

#endif // ABSTRACTLEXER_H
