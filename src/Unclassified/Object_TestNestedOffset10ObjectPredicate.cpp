#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int TestLanguageDependentNameEnding(void*);
// Original: arm9/main @ 0x02068DEC; symbol: func_02068dec; size: 0x30.
extern "C" bool Object_TestNestedOffset10ObjectPredicate(void* unused,char* p){void** e=*(void***)(p+16);if(!e)return false;return TestLanguageDependentNameEnding(*e)==0;}
