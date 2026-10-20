#include <globaldefs.h>
ARM
extern "C" void DispatchLinkedRecordItemCounts(void*, void*, unsigned, unsigned, unsigned);
// Original: arm9/ov025 @ 0x021D8A40; symbol: func_ov025_021d8a40; size: 0x78.
extern "C" void BattleScene_DispatchTargetResultsByCommandCounts(void* owner, unsigned char* state) {
    unsigned counts[2];
    counts[0] = state[9];
    counts[1] = state[8];
    for (int kind = 0; kind < 2; ++kind) {
        for (int index = 0; index < (int)counts[kind]; ++index)
            DispatchLinkedRecordItemCounts(owner, state, 1, 6, (unsigned)kind);
    }
}
