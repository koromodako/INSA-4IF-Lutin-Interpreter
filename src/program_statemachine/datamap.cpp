#include "datamap.h"

#include <string>
#include <sstream>

DataMap::DataMap() :
    map<string, Data>()
{
}

void DataMap::StartConst(const string &identifier)
{
    _current_identifier = identifier;
    _current_data = Data(true, true);
}

void DataMap::StartVar(const string &identifier)
{
    _current_identifier = identifier;
    _current_data = Data(true);
}

void DataMap::SetDataValue(double value)
{
    _current_data.set = true;
    _current_data.value = value;
}

void DataMap::EndData()
{
    insert(make_pair(_current_identifier, _current_data));
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
        if (it->second.exist)
            result << "Error : Use of undeclared identifier '" << it->first << "''" << endl;
        if (it->second.cst && it->second.set)
            result << "Error : read-only variable " << it->first << " is not assignable" << endl;
        if (!it->second.used)
            result << "Warning : Unused parameter '" <<  it->first << "'" << endl;
        else if (!it->second.cst && !it->second.set)
            result << "Error : " <<  it->first << " used but not declared" << endl;
    }
    return result.str();
}
