#include <globaldefs.h>
extern "C" void* Object_GetGlobalConnectionState(); extern "C" int IsFirstWordNonzero(void*); extern "C" int TestInactiveOrPrimaryIndexState(void*);
// Original: arm9/ov017 @ 0x021A01BC; symbol: func_ov017_021a01bc; size: 0x38.
extern "C" ARM void ResourceContext_SetActiveFlagIfIdle(void* self) { void* context=Object_GetGlobalConnectionState();if(!IsFirstWordNonzero(context))return;if(!TestInactiveOrPrimaryIndexState(context))*((unsigned char*)self+0x42e9)=1; }
