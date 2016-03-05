#include "datamaptests.h"

#include "test_macros.h"
#include "src/program_statemachine/datamap.h"

DataMapTests::DataMapTests()
{
    stringify_test();
}

void DataMapTests::stringify_test()
{
    cout << "------------------------ DataMap::Stringify() -----------------------------" << endl;
    string test("var a;\nvar b;\nconst c=5;\n");
    DataMap datamap;
    datamap.insert(make_pair("a", Data(true, false, false, false)));
    datamap.insert(make_pair("b", Data(true, false, false, false)));
    datamap.insert(make_pair("c", Data(true, true, false, false, 5)));
    string stringify = datamap.Stringify();
    if(test != stringify)
    {   FAILED(0);
        PRINT("expected :" << test);
        PRINT("received :"<< stringify);
    }
    else
    {   SUCCESS(0);
    }
    cout << "-------------------------------------- done -----------------------------------" << endl;

}
