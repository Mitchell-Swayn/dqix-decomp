#include <globaldefs.h>
ARM
extern "C" int DispatchSelectedTwoDimensionalTableEntryWhenEnabled(void*, int, int);
// Original: arm9/ov023 @ 0x021FB818; symbol: func_ov023_021fb818; size: 0x60.
extern "C" void* GameState_DispatchPendingTableSelection(unsigned char* state) {
    int row = 0;
    int column = 0;
    if (state[0xb0]) {
        row = 1;
        column = 1;
    } else if (state[0xb1]) {
        row = -1;
        column = 1;
    }
    DispatchSelectedTwoDimensionalTableEntryWhenEnabled(state + 0x20,
        *(int*)(state + 0xa8) + row, *(int*)(state + 0xac) + column);
    state[0xb0] = 0;
    state[0xb1] = 0;
    return *(void**)(state + 0x1c);
}
