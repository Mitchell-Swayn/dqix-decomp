#include <globaldefs.h>
ARM
extern "C" char* TextLookup_FindMatchingByteKeyEntry(void*,int);
// Original: arm9/main @ 0x02067F9C; symbol: func_02067f9c; size: 0x50.
extern "C" int TextLookup_TestRecordOrTokenBitFlag(unsigned* p,void* q,int n){if(p&&((p[2]<<3)>>31))return 1;if(!q)return 0;char* r=TextLookup_FindMatchingByteKeyEntry(q,n);return r?((int)((signed char*)r)[5]<<25)>>31:0;}
