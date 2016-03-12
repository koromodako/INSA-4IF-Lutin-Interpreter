#include "ps5.h"
#include "ps29.h"
#include "src/expression_statemachine/expressionstatemachine.h"

#include "src/debug.h"

AbstractState::TransitionResult PS5::Transition(AbstractStateMachine &machine, Symbol)
{
    // -- DEBUG ------------------------------------------------
    DEBUG("starting expression analysis");
    // -- DEBUG ------------------------------------------------
    ExpressionStateMachine esm(machine.GetLexer(), machine.GetDataMap(), machine.GetInstructionList());
    esm.Run();
    // -- DEBUG ------------------------------------------------
    DEBUG("return from expression analysis");
    // -- DEBUG ------------------------------------------------
    // on demande le merge de l'expression construite
    machine.GetInstructionList().MergeSymbols();
    // dans tous les cas on empile l'état 29
    machine.PileUp(SYM_EXP, new PS29);
    return AbstractState::PILED_UP;
}

PS5::PS5() :
    AbstractState("PS05")
{

}
