#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int TestLanguageDependentNameEnding(void*);
// Original: arm9/main @ 0x02068DBC; symbol: func_02068dbc; size: 0x30.
extern "C" bool TextCondition_TestActorHasNoGermanSpecialEnding(void* unused,char* p){void** e=*(void***)(p+0);if(!e)return false;return TestLanguageDependentNameEnding(*e)==0;}
