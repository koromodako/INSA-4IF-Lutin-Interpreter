#include "datamap.h"

#include "string"
#include "sstream"

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

string DataMap::Stringify()
{
    string consts("");
    string vars("");
    for(DataMap::iterator i = this->begin(); i != this->end(); i++)
	{
        if( i->second.cst )
		{
            ostringstream strs;
            strs << i->second.value;
            consts += "const "+ i->first + "=" + strs.str() + ";\n" ;
			
		}
		else
		{
			vars += "var "+ i->first + ";\n";
			
		}
		
		
	}
	
	return vars+consts;
}


string DataMap::Test()
{
	return string("not implemented yet");
}
