#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov031_02250bfc[];
// Original: arm9/ov031 @ 0x02223FDC; symbol: func_ov031_02223fdc; size: 0x1C.
extern "C" int System_IsGlobalTaskAvailable(void) {
    return *(void **)data_ov031_02250bfc != 0;
}
