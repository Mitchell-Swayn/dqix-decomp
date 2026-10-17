#include <globaldefs.h>
ARM
extern "C" void* data_ov031_022496a4;
extern "C" int func_ov031_02206d90();
extern "C" int func_ov031_022077c0();
// Original: arm9/ov031 @ 0x022142EC; symbol: func_ov031_022142ec; size: 0x48.
extern "C" int System_IsSharedSequenceReady(void) {
    if (data_ov031_022496a4 == 0) return 1;
    if (func_ov031_02206d90() != 0) return 0;
    int status = func_ov031_022077c0();
    return status == 0 || status == -39;
}
