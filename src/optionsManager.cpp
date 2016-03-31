#include "optionsManager.h"
#include "types/types.h"
#include "interfaces/abstractexpression.h"

#include <iostream>

OptionsManager::OptionsManager(DataMap &dataMap, InstructionList &instructionList) :
    _dataMap(dataMap),
    _instructionList(instructionList),
    _display(false),
    _transform(false),
    _execute(false),
    _analysis(false)
{
}

int OptionsManager::CheckOptions(int argc, char *argv[])
{
    for (int i = 1 ; i < argc; ++i)
    {
        if (string(argv[i]) == "-o")
            _transform = true;
        else if (string(argv[i]) == "-p")
            _display = true;
        else if (string(argv[i]) == "-a")
            _analysis = true;
        else if (string(argv[i]) == "-e")
        {   _analysis = true;
            _execute = true;
        }
        else if (argv[i][0] == '-')
            return -1;
        else return i;
    }
    return argc;
}

void OptionsManager::Execute()
{
    bool ok = true;
    if (_transform)
        transform();
    if (_analysis)
        analysis(ok);
    if (!ok)
        cout << "Unable to execute a program with errors." << endl;
    if (_execute && ok)
        execute();
    if (_display && ok)
        print();
}

void OptionsManager::analysis(bool &ok) const
{
    cerr << _instructionList.Test(_dataMap, ok);
    cerr << _dataMap.Test(ok);
}

void OptionsManager::execute() const
{
    list<Instruction>::iterator itIns;
    bool ok;
    double value;
    int i = 0;
    for (itIns = _instructionList.begin() ; itIns != _instructionList.end() ; ++itIns, ++i)
    {
        //Vérification et calcul de l'expression pour SET et PRINT
        if (itIns->expr != NULL)
        {
            ok = false;
            value = itIns->expr->Eval(_dataMap, ok);
            if (!ok)
            {
                cout << "Erreur d'execution à la ligne " << i << endl;
                return;
            }
        }
        //Vérification de la présence de la variable à modifier pour READ et SET
        if (itIns->identifier != "" && !_dataMap.count(itIns->identifier))
        {
            cout << "Variable inconnu à la ligne " << i << endl;
            return;
        }

        //Execution de la ligne
        if (itIns->code == ICODE_PRINT)
            cout << value << endl;
        else if (itIns->code == ICODE_READ)
            cin >> _dataMap[itIns->identifier].value;
        else
            _dataMap[itIns->identifier].value = value;
    }
}

void OptionsManager::print() const
{
    cout << _dataMap.Stringify() << _instructionList.Stringify();
}

void OptionsManager::transform()
{
    AbstractExpression *expr = NULL;
    list<Instruction>::iterator itIns;
    bool ok, skip;

    //Pour chaque expression
    for (itIns = _instructionList.begin() ; itIns != _instructionList.end() ; ++itIns)
    {
        ok = false;
        skip = false;
        if (itIns->expr != NULL)
            expr = itIns->expr->Simplify(_dataMap, ok);
        if (ok && expr != NULL)//Si une simplification a eu lieu...
        {
            delete itIns->expr;
            itIns->expr = expr;
            if (expr->IsNumber() && itIns->code == ICODE_SET)
            {
                double val = expr->Eval(_dataMap, ok);
                if (ok)
                {
                    skip = true;
                    _dataMap[itIns->identifier].value = val;
                    _dataMap[itIns->identifier].isKnown = true;
                }
            }
        }
        if (!skip && itIns->code != ICODE_PRINT)
            _dataMap[itIns->identifier].isKnown = false;
    }
}
