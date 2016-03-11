#include "ps1.h"

#include "ps18.h"
#include "ps11.h"
#include "ps6.h"
#include "ps5.h"
#include "ps3.h"
#include "ps17.h"
#include "ps2.h"
int PS1::Transition(ProgramStateMachine &machine, Symbol symbol)
{
    switch (symbol) {
    case S_CONST:///< mot-clé 'const'
        machine.PileUp(symbol, new PS18());
        break;
    case S_VAR:///< mot-clé 'var'
        machine.PileUp(symbol, new PS11());
        break;
    case S_READ:///< 'lire'
        machine.PileUp(symbol, new PS6());
        break;
    case S_WRITE:///< 'ecrire'
        machine.PileUp(symbol, new PS5());
        break;
    case S_ID:///< identifiant '\w[\w\d]*'
        machine.PileUp(symbol, new PS3());
        break;
    case S_D:///< déclaration
        machine.PileUp(symbol, new PS17());
        break;
    case S_I:///< instruction
        machine.PileUp(symbol, new PS2());
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return -1;
}

PS1::PS1() :
    AbstractPS("PS1")
{

}
