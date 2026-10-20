#include <globaldefs.h>
ARM
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned, void (*)(), unsigned, unsigned);
extern "C" void WfcUtility_AnimateAccessPointListScrollUp();
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222CA64; symbol: func_ov031_0222ca64; size: 0x74.
extern "C" void System_UpdateSharedStateBranch(void) {
    if (*(unsigned short*)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 2) == 0) {
        if ((*(unsigned char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4))[0x59]) return;
        WfcUtility_PlaySequenceArchiveEntry(9);
        (*(unsigned char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4))[0x59] = 1;
        return;
    }
    WfcUtility_PlaySequenceArchiveEntry(0x13);
    (*(void**)(*(unsigned char**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage + 4) + 0x38)) = WfcUtility_CreateTaskWithBorrowedContext(0, WfcUtility_AnimateAccessPointListScrollUp, 0, 0x78);
}
