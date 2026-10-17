#include <globaldefs.h>
ARM
struct PendingContextCalls { unsigned int first; unsigned int second; };
extern "C" struct PendingContextCalls data_ov031_0224e5dc;
extern "C" void func_ov031_02211b98(int, unsigned int, int);
// Original: arm9/ov031 @ 0x022166B4; symbol: func_ov031_022166b4; size: 0x5C.
extern "C" void ProcessorContext_ReleasePendingCalls(void) {
    if (data_ov031_0224e5dc.second != 0) {
        func_ov031_02211b98(1, data_ov031_0224e5dc.second, 0);
        data_ov031_0224e5dc.second = 0;
    }
    if (data_ov031_0224e5dc.first != 0) {
        func_ov031_02211b98(1, data_ov031_0224e5dc.first, 0);
        data_ov031_0224e5dc.first = 0;
    }
}
