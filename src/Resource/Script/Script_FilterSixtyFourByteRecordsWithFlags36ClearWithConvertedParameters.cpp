#include <globaldefs.h>
ARM
extern "C" void* ReadWordAtOffset0();extern "C" int ReadScriptParameterAsInteger(void*);extern "C" void Object_FilterSixtyFourByteRecordsWithFlags36Clear(void*,int);
// Original: arm9/main @ 0x0209D710; symbol: func_0209d710; size: 0x34.
extern "C" int Script_FilterSixtyFourByteRecordsWithFlags36ClearWithConvertedParameters(void* p){void* e=ReadWordAtOffset0();if(!e)return 0;int value=ReadScriptParameterAsInteger(p);Object_FilterSixtyFourByteRecordsWithFlags36Clear(e,value);return 1;}
