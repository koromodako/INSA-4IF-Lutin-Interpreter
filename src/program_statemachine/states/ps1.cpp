#include "ps1.h"

#include "ps18.h"
#include "ps11.h"
#include "ps6.h"
#include "ps5.h"
#include "ps9.h"
#include "ps17.h"
#include "ps2.h"

AbstractState::TransitionResult PS1::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_CONST:///< mot-clé 'const'
        machine.PileUp(symbol, new PS18());
        ret = AbstractState::PILED_UP;
        break;
    case S_VAR:///< mot-clé 'var'
        machine.PileUp(symbol, new PS11());
        ret = AbstractState::PILED_UP;
        break;
    case S_READ:///< 'lire'
        machine.PileUp(symbol, new PS6());
        ret = AbstractState::PILED_UP;
        break;
    case S_WRITE:///< 'ecrire'
        machine.PileUp(symbol, new PS5());
        ret = AbstractState::PILED_UP;
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        // on commence l'ajout d'une instruction d'affectation
        machine.GetInstructionList().StartSet(symbol.buf);
        // cette affectation sera validée après la lecture de l'expression dans l'état 10 et la validation finale dans l'état 28
        machine.PileUp(symbol, new PS9()); /// \todo correction table transition nécessaire ! PS3 -> PS9 in PS1 for id
        ret = AbstractState::PILED_UP;
        break;
    case S_D:///< déclaration
        machine.PileUp(symbol, new PS17());
        ret = AbstractState::PILED_UP;
        break;
    case S_I:///< instruction
        machine.PileUp(symbol, new PS2());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(AbstractStateMachine::ErrorType::SYNTAX_ERROR, symbol);
        break;
    }
    return ret;

}

PS1::PS1() :
    AbstractState("PS01")
{

}
