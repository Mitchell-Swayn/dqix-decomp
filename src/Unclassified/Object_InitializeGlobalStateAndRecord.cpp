#include <globaldefs.h>
extern "C" void Script_ExecuteWithTemporaryPairGlobals(void); extern "C" void TestAllPairHalfwordsEqual(void *);
ARM
// Original: arm9/main @ 0x02028104; symbol: func_02028104; size: 0x18.
extern "C" void Object_InitializeGlobalStateAndRecord(void *p) { Script_ExecuteWithTemporaryPairGlobals(); TestAllPairHalfwordsEqual(p); }
