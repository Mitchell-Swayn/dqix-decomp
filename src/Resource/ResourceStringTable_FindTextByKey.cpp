#include <globaldefs.h>
extern "C" void ResourceStringTable_GetEntryKey();extern "C" unsigned* ResourceStringTable_FindEntryByCallbackKey(unsigned,unsigned,void(*)());
// Original: arm9/main @ 0x020E0440; symbol: func_020e0440; size: 0x2C.
extern "C" ARM unsigned ResourceStringTable_FindTextByKey(unsigned a,unsigned b){if(!a)return 0;unsigned* p=ResourceStringTable_FindEntryByCallbackKey(a,b,ResourceStringTable_GetEntryKey);return p?p[1]:0;}
