#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int TestLanguageDependentNameEnding(void*);
// Original: arm9/main @ 0x02068D5C; symbol: func_02068d5c; size: 0x30.
extern "C" bool Object_TestNestedOffset18ObjectPredicate(void* unused,char* p){void** e=*(void***)(p+24);if(!e)return false;return TestLanguageDependentNameEnding(*e)==0;}
