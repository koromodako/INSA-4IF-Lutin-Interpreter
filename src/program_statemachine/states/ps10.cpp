#include "ps10.h"
#include "ps28.h"
#include "src/expression_statemachine/expressionstatemachine.h"

#include "src/debug.h"

AbstractState::TransitionResult PS10::Transition(AbstractStateMachine &machine, Symbol)
{
    // -- ici on suppose que ce qui suit est une expression on passe donc la main à l'automate d'expression

    // -- DEBUG ------------------------------------------------
    DEBUG("starting expression analysis");
    // -- DEBUG ------------------------------------------------
    ExpressionStateMachine esm(machine.GetLexer(), machine.GetDataMap(), machine.GetInstructionList());
    esm.Run();
    // -- DEBUG ------------------------------------------------
    DEBUG("return from expression analysis");
    // -- DEBUG ------------------------------------------------
    // dans tous les cas on empile l'état 28
    machine.PileUp(SYM_EXP, new PS28);
    return AbstractState::PILED_UP;
}

PS10::PS10() :
    AbstractState("PS10")
{

}
