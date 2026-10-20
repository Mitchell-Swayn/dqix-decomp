#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[];
extern "C" void *Network_GetConnectionWorkspace(unsigned);
typedef void (*StateHandler)(unsigned, int, int);
// Original: arm9/ov031 @ 0x02213270; symbol: func_ov031_02213270; size: 0x64.
extern "C" void GameState_ClearMaskBitAndInvokeHandler(unsigned mask, int arg1, int arg2) {
    unsigned char *state = (unsigned char *)Network_GetConnectionWorkspace(1);
    if (state == 0) return;
    unsigned char flags = state[8];
    if ((flags & mask) == 0) return;
    state[8] = (unsigned char)(flags & ~mask);
    StateHandler handler = *(StateHandler *)(state + 4);
    handler(mask, arg1, arg2);
    if (mask == 1) *(unsigned int *)(NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage + 0xC) = 0;
}
