#include <globaldefs.h>
struct SearchTable { unsigned short* values; unsigned short reserved,count,stride,mask; };
// Original: arm9/main @ 0x0203E63C; symbol: func_0203e63c; size: 0x8C.
extern "C" ARM unsigned FindMaskedHalfwordKeyByBinarySearch(SearchTable* table,unsigned key) { if(!(key&0x8000)) return 0; unsigned short matchedKey=key & table->mask; int low=0; int step=table->stride; while(step>0) { step>>=1; unsigned index=low+step; if(index>=table->count) continue; unsigned short value=table->values[index]; int order; if(matchedKey==value) order=0; else if(matchedKey<value) order=-1; else order=1; if(!order) return index&255; if(order>0) low+=step; } return 0; }
