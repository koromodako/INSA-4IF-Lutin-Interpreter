#include "datamap.h"

#include <string>
#include <sstream>

DataMap::DataMap() :
    map<string, Data>()
{
}

void DataMap::StartConst(const string &identifier)
{
    _currentIdentifier = identifier;
    _currentData = Data(true, true);
}

void DataMap::StartVar(const string &identifier)
{
    _currentIdentifier = identifier;
    _currentData = Data(true);
}

void DataMap::SetDataValue(double value)
{
    _currentData.set = true;
    _currentData.value = value;
}

bool DataMap::EndData()
{
    if (count(_currentIdentifier) == 0)
    {
        insert(make_pair(_currentIdentifier, _currentData));
        return true;
    }
    return false;
}

/**
 * @brief Cette structure décrit une mémoire et les méta-données relatives à cette mémoire.
 */
string DataMap::Stringify() const
{
    stringstream consts;
    stringstream vars;
    for(DataMap::const_iterator i = this->begin() ; i != this->end() ; i++)
	{
        if( i->second.cst )
            consts << "const " << i->first << "=" << i->second.value << ";" << endl;
		else
            vars << "var " << i->first << ";\n";
	}
	
    return vars.str() + consts.str();
}


string DataMap::Test() const
{
    stringstream result;
    for (DataMap::const_iterator it = begin() ; it != end() ; ++it)
    {
        //Variable utilisé et non déclaré - Test 6.4
        if (it->second.exist)
            result << "Error : Use of undeclared identifier '" << it->first << "''" << endl;
        //Constante réaffecté - Test 6.5
        if (it->second.cst && it->second.set)
            result << "Error : read-only variable '" << it->first << "' is not assignable" << endl;
        //Déclaré mais pas utilisé - Test 6.2
        if (!it->second.used)
            result << "Warning : Unused parameter '" <<  it->first << "'" << endl;
        //Déclaré, utilisé, mais pas initialisé -- Test 6.1
        else if (!it->second.cst && !it->second.set && it->second.used)
            result << "Error : '" <<  it->first << "' used but not initialized" << endl;
        //Déclaré, non utilisé et non initialisé - Test 6.3
        else if (!it->second.cst && !it->second.set)
            result << "Warning : '" <<  it->first << "' is not initialized" << endl;
    }
    return result.str();
}
