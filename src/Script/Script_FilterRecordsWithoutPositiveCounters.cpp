#include <globaldefs.h>
extern "C" void* ScriptQueryContext_GetActiveInstance(void*); extern "C" unsigned Script_ReadParameterAsInteger(void*); extern "C" void GameState_FilterRecordsWithoutPositiveCounters(void*,unsigned);
// Original: arm9/main @ 0x0209D5A8; symbol: func_0209d5a8; size: 0x34.
extern "C" int Script_FilterRecordsWithoutPositiveCounters(void* input) { void* state=ScriptQueryContext_GetActiveInstance(input); if(!state)return 0; GameState_FilterRecordsWithoutPositiveCounters(state,Script_ReadParameterAsInteger(input)); return 1; }
