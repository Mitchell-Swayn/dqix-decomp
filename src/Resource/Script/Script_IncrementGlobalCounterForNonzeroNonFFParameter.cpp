#include <globaldefs.h>
ARM
#include <Resource/Script.h>
struct Counter {char pad[6];unsigned short value;};
// Original data: arm9/main @ 0x2109404; symbol: data_02109404.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Counter ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020954E8; symbol: func_020954e8; size: 0x30.
extern "C" int Script_IncrementGlobalCounterForNonzeroNonFFParameter(Script::Parameter* p) {
    int value=p->ToInt();
    if(value==255 || value==0)return 1;
    ++ScriptQueuePackedTimedRecord_UnknownRoleZeroInitializedStorage.value;
    return 1;
}
