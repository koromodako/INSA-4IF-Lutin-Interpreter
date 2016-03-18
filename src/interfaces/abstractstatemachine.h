#ifndef ABSTRACTSTATEMACHINE_H
#define ABSTRACTSTATEMACHINE_H

#include "abstractstate.h"
#include "../lexer/lexer.h"
#include "../types/instructionlist.h"
#include <stack>

using namespace std;
class AbstractState;
/**
 * @brief Cette classe abstraite représente une machine à états pour l'analyse syntaxique quelconque
 */
class AbstractStateMachine
{
public:
    virtual ~AbstractStateMachine();

    /**
     * @brief Execute la machine à état en utilisant le lexer
     */
    virtual void Run(AbstractState * initialState);

    /**
     * @brief Effectue la reduction souhaitée
     * @param size
     *      Taille de la réduction (en nombre d'états)
     */
    void Reduce(Symbol symbol, int size);

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
    inline DataMap & GetDataMap() { return _dMap; }
    inline Lexer & GetLexer() {return _lexer;}

protected:
    AbstractStateMachine(Lexer & lexer, DataMap & dmap, InstructionList & instructions);

private:
    Lexer & _lexer;
    DataMap & _dMap; // cet automate doit remplir cette structure avec les déclarations de variables et constantes
    InstructionList & _instructions;
    stack<string> _errorsStack;         // pile des erreurs
    SymbolStack _symbolsStack;          // pile des symboles
    stack<AbstractState*> _statesStack; // pile des états
};

#endif // ABSTRACTSTATEMACHINE_H
