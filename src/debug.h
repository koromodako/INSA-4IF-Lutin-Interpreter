#ifndef DEBUG_H
#define DEBUG_H

#include "config.h"
#include <iostream>

#ifdef PRINT_DEBUG
#   define DEBUG(msg) cerr << msg << endl
#else
#   define DEBUG(msg)
#endif

#endif // DEBUG_H
