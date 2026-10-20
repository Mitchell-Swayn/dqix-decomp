#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x2290c40; symbol: data_ov031_02290c40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityLoadMessageTable_UnknownRoleZeroInitializedStorage[];
extern "C" void *WfcUtility_PopPointerRingBack(void *);
extern "C" void *WfcUtility_LoadArchiveResource(void *, void *, unsigned);
// Original: arm9/ov031 @ 0x02227630; symbol: func_ov031_02227630; size: 0x58.
extern "C" void *WfcUtility_LoadMessageTable(void *source) {
    unsigned char *global = *(unsigned char **)WfcUtilityLoadMessageTable_UnknownRoleZeroInitializedStorage;
    void *views = WfcUtility_PopPointerRingBack(*(void **)(global + 0x60));
    unsigned local;
    unsigned char *record = (unsigned char *)WfcUtility_LoadArchiveResource(source, &local, 4);
    unsigned char *base = record + 0x20;
    *(void **)((char *)views + 8) = record;
    *(void **)views = base + 0x10;
    *(void **)((char *)views + 4) = base + *(unsigned *)(base + 4) + 8;
    return views;
}
