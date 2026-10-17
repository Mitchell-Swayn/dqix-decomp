#include <globaldefs.h>
extern "C" void* ReadWordAtOffset0(void*); extern "C" unsigned ReadScriptParameterAsInteger(void*); extern "C" void GameState_FilterRecordsWithoutPositiveCounters(void*,unsigned);
// Original: arm9/main @ 0x0209D5A8; symbol: func_0209d5a8; size: 0x34.
extern "C" int DispatchOneConvertedParameterToResolvedState(void* input) { void* state=ReadWordAtOffset0(input); if(!state)return 0; GameState_FilterRecordsWithoutPositiveCounters(state,ReadScriptParameterAsInteger(input)); return 1; }
