#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void FilterSixtyFourByteRecordsByFourthFlagMask(void*,int,int);
// Original: arm9/main @ 0x0209CFCC; symbol: func_0209cfcc; size: 0x44.
extern "C" ARM int Script_FilterRecordsByFourthFlagByteMask(char* p){void* state=ReadWordAtOffset0();if(!state)return 0;int first=ReadScriptParameterAsInteger(p);int second=ReadScriptParameterAsInteger(p+8);FilterSixtyFourByteRecordsByFourthFlagMask(state,first,second);return 1;}
