#include "datamap.h"

#include "string"
#include "sstream"

/**
 * @brief Cette structure décrit une mémoire et les méta-données relatives à cette mémoire.
 */
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
