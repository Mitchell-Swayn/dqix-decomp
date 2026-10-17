#include <globaldefs.h>
extern "C" void* Object_GetGlobalConnectionState();
extern "C" int TestActiveWordAndGlobalStateNonzero(void*);
extern "C" int Object_TestIndexedByte100EFlagByKey(void*,int);
// Original: arm9/ov017 @ 0x021959B4; symbol: func_ov017_021959b4; size: 0x38.
extern "C" ARM int TestContextModeAndZeroSlot() { void* context=Object_GetGlobalConnectionState(); if(TestActiveWordAndGlobalStateNonzero(context)) { if(Object_TestIndexedByte100EFlagByKey(context,0)) return 1; } return 0; }
