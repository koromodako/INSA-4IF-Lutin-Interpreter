#include "ps10.h"
#include "ps28.h"

#include "src/expression_statemachine/expressionstatemachine.h"

AbstractState::TransitionResult PS10::Transition(AbstractStateMachine &machine, Symbol symbol)
{
    // -- ici on suppose que ce qui suit est une expression on passe donc la main à l'automate d'expression
    ExpressionStateMachine esm(machine.GetLexer(), machine.GetDataMap(), machine.GetInstructionList());
    esm.Run();

    AbstractState::TransitionResult ret = AbstractState::UNEXPECTED;
    switch (symbol.code) {
    case S_EXP:///< expression arithmetique
        //machine.GetDataMap().SetDataValue(symbol.buf); autre automate
        machine.PileUp(symbol, new PS28());
        ret = AbstractState::PILED_UP;
        break;
    default:
        machine.Unexpected(symbol);
        break;
    }
    return ret;

}

PS10::PS10() :
    AbstractState("PS10")
{

}
