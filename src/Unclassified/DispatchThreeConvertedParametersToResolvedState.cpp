#include <globaldefs.h>
ARM
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void func_0209f030(void*,int,int,int);
// Original: arm9/main @ 0x0209D150; symbol: func_0209d150; size: 0x54.
extern "C" int DispatchThreeConvertedParametersToResolvedState(char* p){void* e=ReadWordAtOffset0();if(!e)return 0;int a=ReadScriptParameterAsInteger(p);int b=ReadScriptParameterAsInteger(p+8);int c=ReadScriptParameterAsInteger(p+16);func_0209f030(e,a,b,c);return 1;}
