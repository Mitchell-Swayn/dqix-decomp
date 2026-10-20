#include <globaldefs.h>
#include "Resource/Script.h"

// Original data: arm9/main @ 0x20fdd30; symbol: data_020fdd30.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" void* ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage;
extern "C" {
void* ActorPathGraph_FindNodeById(void* manager, int id);
void ActorPathGraph_AppendEdge(void* manager, void** pair);
}

// Looks up the objects named by the script parameters and links each with the previous one.
// Original: arm9/main @ 0x02027E44; symbol: func_02027e44; size: 0xA8.
extern "C" ARM int Script_LinkConsecutiveResolvedIds(Script::Parameter* params, int count) {
    void* pair[2];
    pair[1] = 0;
    pair[0] = 0;

    int id = (params++)->ToInt();
    count--;
    pair[0] = ActorPathGraph_FindNodeById(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage, id);
    while (count >= 0) {
        id = (params++)->ToInt();
        count--;
        pair[1] = ActorPathGraph_FindNodeById(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage, id);
        if (pair[0] && pair[1]) ActorPathGraph_AppendEdge(ScriptSwapTwoSelectedRecords_UnknownRoleZeroInitializedStorage, pair);
        if (pair[1]) pair[0] = pair[1];
    }
    return 1;
}
