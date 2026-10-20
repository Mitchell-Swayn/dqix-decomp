#include <globaldefs.h>
ARM
#include <Resource/Script.h>
// Original data: arm9/main @ 0x20fdd30; symbol: data_020fdd30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[2];
extern "C" void AllocateAndClearPairArray(void*,void*,int);
// Original: arm9/main @ 0x02027FBC; symbol: func_02027fbc; size: 0x24.
extern "C" int Script_AllocatePairArrayFromIntegerParameter(const Script::Parameter* parameter) {
 int index=parameter->ToInt();
 AllocateAndClearPairArray(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[0],ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage[1],index);
 return 1;
}
