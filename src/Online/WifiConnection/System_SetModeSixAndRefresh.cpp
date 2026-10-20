#include <globaldefs.h>
ARM
extern "C" void Multiboot_SetParentState(unsigned short value);
extern "C" void MB_End(void);
// Original: arm9/ov031 @ 0x02238DA0; symbol: func_ov031_02238da0; size: 0x14.
extern "C" void System_SetModeSixAndRefresh(void) {
    Multiboot_SetParentState(6);
    MB_End();
}
