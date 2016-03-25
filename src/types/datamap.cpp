#include "datamap.h"

#include <string>
#include <stdlib.h>
#include <sstream>
#include <iostream>

DataMap::DataMap() :
    map<string, Data>()
{
}

void DataMap::StartConst(const string &identifier)
{
    _currentIdentifier = identifier;
    _currentData = Data(true, true);
}

bool DataMap::AppendVar(const string &identifier)
{
    _currentIdentifier = identifier;
    _currentData = Data(true);
    return EndData();
}

void DataMap::AddIfNotExist(const string &identifier)
{
    DataMap::iterator d = find(identifier);
    if (d == end())
        insert(make_pair(identifier, Data()));
}

bool DataMap::SetDataValue(double value)
{
    if (!_currentData.cst)
        _currentData.set = true;
    _currentData.value = value;
    return EndData();
}

bool DataMap::SetDataValue(string value)
{
    if (!_currentData.cst)
        _currentData.set = true;
    _currentData.value = atof(value.c_str());
    return EndData();
}

bool DataMap::EndData()
{
    bool ok = true;
    DataMap::iterator d = find(_currentIdentifier);
    if (d == end())
    {   insert(make_pair(_currentIdentifier, _currentData));
    }
    else
    {   _lastError = "redefinition of ’"+ d->first+"’";
       ok = false;
    }
    // on reset les variables (buffers) internes
    _currentIdentifier = "";
    _currentData = Data();
    return ok;
}

/**
 * @brief Cette structure décrit une mémoire et les méta-données relatives à cette mémoire.
 */
string DataMap::Stringify() const
{
    stringstream result;
    for(DataMap::const_iterator i = this->begin() ; i != this->end() ; i++)
	{
        if( i->second.cst )
            result << "const " << i->first << " = " << i->second.value << ";" << endl;
		else
            result << "var " << i->first << ";" << endl;
	}
	
    return result.str();
}


string DataMap::Test() const
{
    stringstream result;
    for (DataMap::const_iterator it = begin() ; it != end() ; ++it)
    {
        //Variable utilisé et non déclaré - Test 6.4
        if (!it->second.exist)
        {
            result << "Error : Use of undeclared identifier '" << it->first << "'" << endl;
            continue;
        }

        //Déclaré mais pas utilisé - Test 6.2
        if (!it->second.used)
            result << "Warning : Unused parameter '" <<  it->first << "'" << endl;
        //Déclaré, non utilisé et non initialisé - Test 6.3
        if (!it->second.cst && !it->second.set && !it->second.used)
            result << "Warning : '" <<  it->first << "' is not initialized" << endl;
    }
    return result.str();
}
