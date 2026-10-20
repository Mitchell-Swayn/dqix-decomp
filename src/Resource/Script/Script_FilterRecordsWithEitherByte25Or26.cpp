#include <globaldefs.h>
extern "C" void* ScriptQueryContext_GetActiveInstance();extern "C" int Script_ReadParameterAsInteger(int);extern "C" void ScriptQueryContext_FilterByEitherAuxiliaryMarker(void*,int);
// Original: arm9/main @ 0x0209D688; symbol: func_0209d688; size: 0x34.
extern "C" ARM int Script_FilterRecordsWithEitherByte25Or26(int a){void* p=ScriptQueryContext_GetActiveInstance();if(!p)return 0;ScriptQueryContext_FilterByEitherAuxiliaryMarker(p,Script_ReadParameterAsInteger(a));return 1;}
