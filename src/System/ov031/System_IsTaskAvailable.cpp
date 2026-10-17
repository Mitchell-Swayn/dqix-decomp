#include <globaldefs.h>
ARM
extern void *data_ov031_02250c00;
// Original: arm9/ov031 @ 0x02225C74; symbol: func_ov031_02225c74; size: 0x1C.
extern "C" int System_IsTaskAvailable(void) {
    return data_ov031_02250c00 != 0;
}
