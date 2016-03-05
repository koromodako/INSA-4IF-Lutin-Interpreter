#ifndef TEST_MACROS_H
#define TEST_MACROS_H

#include <iostream>
#define FAILED(info)   cerr << "test - " << info << " - FAILED !" << endl
#define SUCCESS(info)  cout << "test - " << info << " - SUCCESS !" << endl
#define PRINT(msg)      cerr << msg << endl

#endif // TEST_MACROS_H
