#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void *PartySync_GetSharedRecordTable();
struct E;
extern "C" E *PartySync_FindEntryByKey(E *p,unsigned int key);
// Original data: arm9/ov017 @ 0x21d7654; symbol: data_ov017_021d7654.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0100f87f000034430000f0410000f04100003443.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" unsigned short GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes[];
// Original: arm9/ov017 @ 0x021A1A20; symbol: func_ov017_021a1a20; size: 0xB0.
extern "C" unsigned GameState_AllocateUnusedHighIdentifier(void) {
    void *state = _ZN9GameState11GetInstanceEv();
    E *records = (E *)PartySync_GetSharedRecordTable();
    unsigned low = 0x7ff8;
    unsigned high = low + 7;
restart:
    if (GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes[1] > high) GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes[1] = low;
    for (int i = 0; i < 4; ++i) {
        char *object = (char *)GameState_GetObjectWithFlag100(state,i);
        if (object && GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes[1] == *(unsigned short *)(object + 0x1b2)) {
            ++GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes[1];
            goto restart;
        }
    }
    if (PartySync_FindEntryByKey(records,GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes[1])) {
        ++GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes[1];
        goto restart;
    }
    return GameStateAllocateUnusedHighIdentifier_UnknownRoleInitializedBytes[1]++;
}
