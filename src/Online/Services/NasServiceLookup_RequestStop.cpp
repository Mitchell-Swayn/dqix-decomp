#include <globaldefs.h>
ARM
extern "C" void System_UpdateContextWhenActive(void);
// Original: arm9/ov031 @ 0x022125BC; symbol: func_ov031_022125bc; size: 0xC.
extern "C" void NasServiceLookup_RequestStop(void) {
    System_UpdateContextWhenActive();
}
