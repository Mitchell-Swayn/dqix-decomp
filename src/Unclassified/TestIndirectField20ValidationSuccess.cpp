#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int TestLanguageDependentNameEnding(void*);
// Original: arm9/main @ 0x02068D8C; symbol: func_02068d8c; size: 0x30.
extern "C" bool TestIndirectField20ValidationSuccess(void* unused,char* p){void** e=*(void***)(p+32);if(!e)return false;return TestLanguageDependentNameEnding(*e)==0;}
