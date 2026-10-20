#include <globaldefs.h>
extern "C" void* ActionData_ResolvePayloadOffsetOrFallback(void*,void*,int);
// Original: arm9/main @ 0x02079808; symbol: func_02079808; size: 0x38.
extern "C" ARM int ActionData_ResolveDefinitionPayloadPointers(void* p,void** out){out[0]=ActionData_ResolvePayloadOffsetOrFallback(p,out[0],0);out[13]=ActionData_ResolvePayloadOffsetOrFallback(p,out[13],0);return 1;}
