#include <globaldefs.h>
#include <Resource/Script.h>
#pragma optimization_level 4
#pragma optimize_for_size off
// Original data: arm9/main @ 0x20fdd30; symbol: data_020fdd30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage;
extern "C" void ActorPathGraph_AppendStatePair(int, unsigned short *);
// Original: arm9/main @ 0x0202800C; symbol: func_0202800c; size: 0x3C.
extern "C" int Script_ConvertTwoParametersToHalfwordPair(Script::Parameter *param_1, unsigned int unused2, unsigned int unused3, unsigned int param_4) {
    unsigned int first = (unsigned int)param_1->ToInt();
    unsigned short second = (unsigned short)((Script::Parameter *)((char *)param_1 + 8))->ToInt();
    unsigned short local[2];
    local[1] = second;
    unsigned int target = ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage;
    local[0] = (unsigned short)first;
    ActorPathGraph_AppendStatePair(target, local);
    return 1;
}
