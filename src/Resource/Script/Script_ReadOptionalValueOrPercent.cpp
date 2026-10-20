#include <globaldefs.h>
ARM
extern "C" {void* ScriptQueryContext_GetActiveInstance();int Script_ReadParameterAsInteger(void*);int ScriptQueryContext_GetLinkedZoneIdOrRegion(void*,int);void Script_WriteIntegerReferenceOutput(void*,int);
// Original: arm9/main @ 0x0209D44C; symbol: func_0209d44c; size: 0x40.
int Script_ReadOptionalValueOrPercent(unsigned char* p){void* q=ScriptQueryContext_GetActiveInstance();if(!q)return 0;int x=Script_ReadParameterAsInteger(p);x=ScriptQueryContext_GetLinkedZoneIdOrRegion(q,x);Script_WriteIntegerReferenceOutput(p+8,x);return 1;}}
