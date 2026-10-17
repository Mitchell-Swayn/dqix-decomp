#include <globaldefs.h>
ARM
extern "C" void* TextLookup_ReadGlobalResourceForTypeEight(int);extern "C" void* FindStridedValueByTwoByteKey(void*,const void*);extern "C" void* Object_ReadGlobalDisplayContextWord();extern "C" void* ReturnZero_Main02094B44(void*,int);
// Original: arm9/main @ 0x02042A50; symbol: func_02042a50; size: 0x40.
extern "C" void* TextLookup_FindKeyInPrimaryThenFallbackResource(int n,const void* key){if(!key)return 0;void* found=FindStridedValueByTwoByteKey(TextLookup_ReadGlobalResourceForTypeEight(n),key);if(found)return found;return FindStridedValueByTwoByteKey(ReturnZero_Main02094B44(Object_ReadGlobalDisplayContextWord(),n),key);}
