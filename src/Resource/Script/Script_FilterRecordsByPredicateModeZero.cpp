#include <globaldefs.h>
ARM
extern "C" void* ReadWordAtOffset0();extern "C" unsigned ReadScriptParameterAsInteger(void*);extern "C" void FilterSixtyFourByteRecordsByValuePredicate(void*,unsigned,unsigned);
// Original: arm9/main @ 0x0209CF00; symbol: func_0209cf00; size: 0x44.
extern "C" int Script_FilterRecordsByPredicateModeZero(unsigned char* param){void* object=ReadWordAtOffset0();if(!object)return 0;unsigned a=ReadScriptParameterAsInteger(param);unsigned b=ReadScriptParameterAsInteger(param+8);FilterSixtyFourByteRecordsByValuePredicate(object,a,b);return 1;}
