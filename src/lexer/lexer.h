#ifndef ABSTRACTLEXER_H
#define ABSTRACTLEXER_H

#include "../types/types.h"

#include <fstream>

using namespace std;

/**
 * @brief Cette classe représente un lexer chargé de l'analyse lexicale
 */
class Lexer
{
public:
    Lexer(ifstream & stream);
    ~Lexer(){}
    /**
     * @brief Ajoute le symbole donnée sous la tête de lecture
     */
    void AddExpectedSymbol(const string &symbol);

    /**
     * @brief Met à jour le buffer en déplaçant la tête de lecture
     */
    void MoveForward();
    /**
     * @brief Retourne le symbole actuellement sous la tête de lecture
     * @return
     */
    Symbol GetNext();
    /**
     * @brief Retourne le numéro de la ligne courante du lexer
     * @return
     */
    inline int GetLine() const { return _line; }
    /**
     * @brief Retourne le numéro de la colonne courante du lexer
     * @return
     */
    inline int GetCol() const { return _col; }

private:
    string _buf;
    size_t _matched_length;
    ifstream & _stream;
    int _line;
    int _col;
};

#endif // ABSTRACTLEXER_H
