#include <globaldefs.h>
ARM
extern "C" unsigned ReadWordAtOffset0(); extern "C" unsigned ReadScriptParameterAsInteger(char*); extern "C" void Object_FilterSixtyFourByteRecordsByValuePredicate(unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x0209CF44; symbol: func_0209cf44; size: 0x44.
 extern "C" int Script_FilterSixtyFourByteRecordsByValuePredicateWithConvertedParameters(char* p){unsigned state=ReadWordAtOffset0();if(!state)return 0;unsigned a=ReadScriptParameterAsInteger(p);unsigned b=ReadScriptParameterAsInteger(p+8);Object_FilterSixtyFourByteRecordsByValuePredicate(state,a,b);return 1;}
