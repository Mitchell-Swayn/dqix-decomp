#include <globaldefs.h>
ARM
extern "C" unsigned* FindNonnegativeKeyInEntryArray(void*,int);extern "C" unsigned FindRecordValueByKeyOrZero(void*,int);
// Original: arm9/main @ 0x02080FE0; symbol: func_02080fe0; size: 0x30.
extern "C" void SetKeyedRecordWordFromSecondaryKeyLookup(unsigned char* p,int key,int value){unsigned* q=FindNonnegativeKeyInEntryArray(p+4,key);if(!q)return;*q=FindRecordValueByKeyOrZero(*(void**)p,value);}
