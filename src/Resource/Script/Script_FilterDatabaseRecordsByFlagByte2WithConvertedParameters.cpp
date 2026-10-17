#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void FilterDatabaseRecordsByFlagByte2(void*,int,int);
// Original: arm9/main @ 0x0209CF88; symbol: func_0209cf88; size: 0x44.
extern "C" ARM int Script_FilterDatabaseRecordsByFlagByte2WithConvertedParameters(char* p){void* state=ReadWordAtOffset0();if(!state)return 0;int first=ReadScriptParameterAsInteger(p);int second=ReadScriptParameterAsInteger(p+8);FilterDatabaseRecordsByFlagByte2(state,first,second);return 1;}
