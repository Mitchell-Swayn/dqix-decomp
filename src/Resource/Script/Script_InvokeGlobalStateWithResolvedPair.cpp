#include <globaldefs.h>
extern "C" void* ReadGlobalValueAt02108844();extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void SetMappedValueWithHighKeyOffsetAdjustment(void*,int,int);
// Original: arm9/main @ 0x0209D48C; symbol: func_0209d48c; size: 0x44.
extern "C" ARM int Script_InvokeGlobalStateWithResolvedPair(char* p){void* state=ReadGlobalValueAt02108844();if(!state)return 0;int first=ReadScriptParameterAsInteger(p);int second=ReadScriptParameterAsInteger(p+8);SetMappedValueWithHighKeyOffsetAdjustment(state,first,second);return 1;}
