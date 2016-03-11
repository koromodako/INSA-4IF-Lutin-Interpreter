#ifndef DEBUG_H
#define DEBUG_H

#include "config.h"
#include <iostream>

#ifdef PRINT_DEBUG
#   define DEBUG(msg) cerr << "-!-[DEBUG] - " <<  msg << endl << flush
#   define DBG_PRT(msg) cerr << msg
#else
#   define DEBUG(msg)
#   define DBG_PRT(msg)
#endif

#endif // DEBUG_H
