#include <globaldefs.h>
ARM
extern unsigned char data_ov031_0224e5c4[];
extern "C" void GameState_ClearMaskBitAndInvokeHandler(unsigned, int, int);
// Original: arm9/ov031 @ 0x022135BC; symbol: func_ov031_022135bc; size: 0x38.
extern "C" void GameState_InvokeMaskHandlersEightAndSixteen(void) {
    GameState_ClearMaskBitAndInvokeHandler(8, *(int *)(data_ov031_0224e5c4 + 8), 0xC);
    GameState_ClearMaskBitAndInvokeHandler(0x10, *(int *)(data_ov031_0224e5c4 + 0x10), 0xD18);
}
