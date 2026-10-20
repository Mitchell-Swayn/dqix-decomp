#include <globaldefs.h>
ARM
extern "C" void* TextLookup_ReadGlobalResourceForTypeEight(int);extern "C" void* TextLookup_FindValueByBytePairKey(void*,const void*);extern "C" void* DisplayContext_GetGlobalInstance();extern "C" void* DisplayContext_ReturnNoFallbackResource(void*,int);
// Original: arm9/main @ 0x02042A50; symbol: func_02042a50; size: 0x40.
extern "C" void* TextLookup_FindKeyInPrimaryThenFallbackResource(int n,const void* key){if(!key)return 0;void* found=TextLookup_FindValueByBytePairKey(TextLookup_ReadGlobalResourceForTypeEight(n),key);if(found)return found;return TextLookup_FindValueByBytePairKey(DisplayContext_ReturnNoFallbackResource(DisplayContext_GetGlobalInstance(),n),key);}
