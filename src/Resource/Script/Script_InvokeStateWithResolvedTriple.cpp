#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void FilterSixtyFourByteRecordsByMinimumGroupSize(void*,int,int,int);
// Original: arm9/main @ 0x0209D6BC; symbol: func_0209d6bc; size: 0x54.
extern "C" ARM int Script_InvokeStateWithResolvedTriple(char* p){void* owner=ReadWordAtOffset0();if(!owner)return 0;int a=ReadScriptParameterAsInteger(p);int b=ReadScriptParameterAsInteger(p+8);int c=ReadScriptParameterAsInteger(p+16);FilterSixtyFourByteRecordsByMinimumGroupSize(owner,a,b,c);return 1;}
