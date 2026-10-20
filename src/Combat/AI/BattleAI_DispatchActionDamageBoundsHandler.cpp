#include <globaldefs.h>
ARM

// Original data: arm9/ov024 @ 0x21ffda4; symbol: data_ov024_021ffda4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 00000000886a1f02e86a1f02286b1f025c6b1f0200000000000000008c6b1f0200000000c06b1f02f06b1f02406c1f02706c1f02c06c1f02246d1f022c6d1f02 ...; full span in module reference.
// Observed span: 264 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov024.md.
extern "C" unsigned char BattleAIDispatchActionDamageBoundsHandler_UnknownRoleProcedureReferenceRecords[];

// Original: arm9/ov024 @ 0x021F736C; symbol: func_ov024_021f736c; size: 0x4C.
extern "C" int BattleAI_DispatchActionDamageBoundsHandler(void *object) {
    void *state = *(void **)((char *)object + 0x10);
    if (state == 0) {
        return 0;
    }
    unsigned int index = (*(unsigned int *)((char *)state + 0x18) << 5) >> 23;
    if (index >= 0x42) {
        return 0;
    }
    void (*handler)(void *) = *(void (**)(void *))(BattleAIDispatchActionDamageBoundsHandler_UnknownRoleProcedureReferenceRecords + index * 4);
    if (handler == 0) {
        return 0;
    }
    return ((int (*)(void *))handler)(object);
}
