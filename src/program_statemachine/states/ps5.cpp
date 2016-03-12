#include "ps5.h"
#include "ps29.h"
#include "src/expression_statemachine/expressionstatemachine.h"

#include "src/debug.h"

AbstractState::TransitionResult PS5::Transition(AbstractStateMachine &machine, Symbol)
{
    machine.GetInstructionList().StartPrint();
    // -- DEBUG ------------------------------------------------
    DEBUG("starting expression analysis");
    // -- DEBUG ------------------------------------------------
    ExpressionStateMachine esm(machine.GetLexer(), machine.GetDataMap(), machine.GetInstructionList());
    esm.Run();
    // -- DEBUG ------------------------------------------------
    DEBUG("return from expression analysis");
    // -- DEBUG ------------------------------------------------
    // note : l'ajout final de l'instruction dans la liste d'instruction se fait dans l'état 29
    // dans tous les cas on empile l'état 29
    machine.PileUp(SYM_EXP, new PS29);
    return AbstractState::PILED_UP;
}

PS5::PS5() :
    AbstractState("PS05")
{

}
