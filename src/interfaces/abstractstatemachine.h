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
    /**
     * @brief Cette énumération définit les types d'erreur pouvant être rencontrés
     */
    enum ErrorType{
        WARNING,        ///< Avertissement
        SYNTAX_ERROR,   ///< Erreur de syntaxe
        LEXICAL_ERROR,  ///< Erreur lexicale
        ERROR           ///< Erreur
    };

    virtual ~AbstractStateMachine();

    /**
     * @brief Exécute la machine à états en utilisant le lexer
     */
    virtual bool Run(AbstractState * initialState);

    /**
     * @brief Effectue la réduction souhaitée
     * @param size
     *      Taille de la réduction (en nombre d'états)
     */
    void Reduce(const Symbol & symbol, int size);

    /**
     * @brief Effectue la transition vers l'état suivant
     * @param symbol
     *      Symbole suivant
     * @param state
     *      Etat suivant
     */
    void PileUp(const Symbol & symbol, AbstractState * state);

    /**
     * @brief Effectue la recupération sur erreur s'il y a lieu ou place la machine à état dans un état d'erreur
     * @param symbole
     *      Symbole courant
     * @param state
     *      Nouvel état
     * @return vrai si l'exécution doit continuer, faux dans le cas contraire
     */
    bool Unexpected(ErrorType type, const Symbol & symbol);
    /**
     * @brief Effectue la recupération sur erreur s'il y a lieu ou place la machine à état dans un état d'erreur
     * @param symbole
     *      Symbole courant
     * @param state
     *      Nouvel état
     */
    void Unexpected(ErrorType type, const string & message);
    /**
     * @brief Retourne une référence sur la liste d'instructions manipulée par la machine à états
     * @return
     */
    inline InstructionList & GetInstructionList() { return _instructions; }
    /**
     * @brief Retourne une référence sur le dictionnaire des mémoires manipulé par la machine à états
     * @return
     */
    inline DataMap & GetDataMap() { return _dMap; }
    /**
     * @brief Retourne une référence au lexer manipulé par la machine à états
     * @return
     */
    inline Lexer & GetLexer() {return _lexer;}

protected:
    // constructeur protégé (classe abstraite)
    AbstractStateMachine(Lexer & lexer, DataMap & dmap, InstructionList & instructions);

private:
    Lexer & _lexer;
    DataMap & _dMap;                    // l'automate doit remplir cette structure avec les déclarations de variables et constantes
    InstructionList & _instructions;    // l'automate doit remplir cette liste avec les instructions qu'il rencontre
    stack<string> _errorsStack;         // pile des erreurs
    SymbolStack _symbolsStack;          // pile des symboles
    stack<AbstractState*> _statesStack; // pile des états
};

#endif // ABSTRACTSTATEMACHINE_H
