#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void Object_FilterSixtyFourByteRecordsByInitialFlagMask(void*,int,int);
// Original: arm9/main @ 0x0209CE78; symbol: func_0209ce78; size: 0x44.
extern "C" ARM int Script_FilterSixtyFourByteRecordsByInitialFlagMaskWithConvertedParameters(char* p){void* state=ReadWordAtOffset0();if(!state)return 0;int first=ReadScriptParameterAsInteger(p);int second=ReadScriptParameterAsInteger(p+8);Object_FilterSixtyFourByteRecordsByInitialFlagMask(state,first,second);return 1;}
