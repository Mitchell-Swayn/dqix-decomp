#include <globaldefs.h>
ARM
extern "C" int ReadLastGlobalStackEntryOrMinusOne(void);
extern "C" void func_ov026_021dbe44(char* state);
// Original: arm9/ov000 @ 0x02163B40; symbol: func_ov000_02163b40; size: 0x20.
extern "C" void System_CallStateFunctionWhenLastStackEntryIsThree(char* state) { if (ReadLastGlobalStackEntryOrMinusOne() == 3) func_ov026_021dbe44(state); }
