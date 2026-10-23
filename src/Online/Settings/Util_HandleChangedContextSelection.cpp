#include <globaldefs.h>
ARM
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void* WfcUtility_CreateTaskWithBorrowedContext(unsigned,void (*)(void*,void*),void*,unsigned);
extern "C" void WfcUtility_AnimateAccessPointListScrollDown(void*,void*);
struct Context { unsigned short a,selected; unsigned char *state; };
// Original data: arm9/ov031 @ 0x2290c8c; symbol: data_ov031_02290c8c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Context TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0222CAD8; symbol: func_ov031_0222cad8; size: 0x84.
extern "C" void Util_HandleChangedContextSelection() {
    unsigned char *state = TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state;
    if (TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.selected == *(unsigned short*)(state + 0x40) || state[0x51] <= 4) {
        if (state[0x59]) return;
        WfcUtility_PlaySequenceArchiveEntry(9);
        TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state[0x59] = 1;
    } else {
        WfcUtility_PlaySequenceArchiveEntry(19);
        void *operation = WfcUtility_CreateTaskWithBorrowedContext(0,WfcUtility_AnimateAccessPointListScrollDown,0,120);
        *(void**)(TextDrawSplitAsciiRow_UnknownRoleZeroInitializedStorage.state + 0x38) = operation;
    }
}
