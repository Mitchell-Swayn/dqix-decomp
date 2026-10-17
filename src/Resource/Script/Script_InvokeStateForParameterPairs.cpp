#include <globaldefs.h>
#include <Resource/Script.h>
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(Script::Parameter*);extern "C" void Object_FilterSixtyFourByteRecordsByIndexedHalfword(void*,int,int,int);
#pragma optimization_level 4
// Original: arm9/main @ 0x0209D0DC; symbol: func_0209d0dc; size: 0x74.
extern "C" ARM int Script_InvokeStateForParameterPairs(Script::Parameter* p,int count){void* target=ReadWordAtOffset0();if(!target)return 0;int first=ReadScriptParameterAsInteger(p);++p;for(int i=1;i<count;i+=2){int a=ReadScriptParameterAsInteger(p);Script::Parameter* next=p+1;p+=2;int b=ReadScriptParameterAsInteger(next);Object_FilterSixtyFourByteRecordsByIndexedHalfword(target,first,a,b);}return 1;}
