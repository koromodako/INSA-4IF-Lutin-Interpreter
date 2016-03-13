#ifndef DEBUG_H
#define DEBUG_H

#include "config.h"
#include <iostream>

#   define ERROR(msg) cerr << "-!-[ERROR] -" << msg << endl << flush

#ifdef PRINT_DEBUG

#   define DEBUG(msg) cerr << "[DEBUG] - " <<  msg << endl << flush
#   define DBG_PRT(msg) cerr << msg

#   define DBG_SYM_LIST(symbols) \
    for(SymbolList::iterator s = (symbols).begin(); s != (symbols).end(); ++s) \
    {   switch (s->code) { \
        case S_ID:      DBG_PRT(s->buf);        break; \
        case S_NUM:     DBG_PRT(s->buf);        break; \
        case S_PLUS:    DBG_PRT("+");           break; \
        case S_MINUS:   DBG_PRT("-");           break; \
        case S_MULT:    DBG_PRT("*");           break; \
        case S_DIV:     DBG_PRT("/");           break; \
        case S_PO:      DBG_PRT("(");           break; \
        case S_PF:      DBG_PRT(")");           break; \
        default:        DBG_PRT("unexpected");  break; \
        } \
    } \
    DBG_PRT(endl)

#else

#   define DEBUG(msg)
#   define DBG_PRT(msg)
#   define DBG_SYM_LIST(list)

#endif



#endif // DEBUG_H
