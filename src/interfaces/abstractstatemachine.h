#ifndef ABSTRACTSTATEMACHINE_H
#define ABSTRACTSTATEMACHINE_H

#include "abstractstate.h"
#include "src/lexer/lexer.h"
#include "src/program_statemachine/instructionlist.h"
#include <stack>

using namespace std;

/**
 * @brief Cette classe abstraite représente une machine à états pour l'analyse syntaxique quelconque
 */
class AbstractStateMachine
{
public:
    virtual ~AbstractStateMachine(){}

    /**
     * @brief Effectue la reduction souhaitée
     * @param size
     *      Taille de la réduction (en nombre d'états)
     */
    void Reduce(int size);

    /**
     * @brief Effectue la transition vers l'état suivant
     * @param symbol
     *      Symbole suivant
     * @param state
     *      Etat suivant
     */
    void PileUp(Symbol symbol, AbstractState * state);

    /**
     * @brief Effectue la recupération sur erreur s'il y a lieu ou place la machine à état dans un état d'erreur
     * @param symbole
     *      Symbole courant
     * @param state
     *      Nouvel état
     */
    void Unexpected(Symbol symbol);

    inline InstructionList & GetInstructionList() { return _instructions; } // inline explicite
    inline DataMap & GetDataMap() { return _dmap; }
    inline Lexer & GetLexer() {return _lexer;}

protected:
    AbstractStateMachine(Lexer & lexer, DataMap & dmap, InstructionList & instructions);

    inline Lexer & lexer() { return _lexer; }                               // inline explicite
                             // inline explicite

private:
    Lexer & _lexer;
    DataMap & _dmap; // cet automate doit remplir cette structure avec les déclarations de variables et constantes
    InstructionList & _instructions;
    stack<string> _error_stack;         // pile des erreurs
    stack<Symbol> _symbols_stack;          // pile des symboles
    stack<AbstractState*> _state_stack; // pile des états
};

#endif // ABSTRACTSTATEMACHINE_H
