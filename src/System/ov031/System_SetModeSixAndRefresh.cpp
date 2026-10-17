#include <globaldefs.h>
ARM
extern "C" void func_ov031_02239108(unsigned short value);
extern "C" void func_ov027_021dcd20(void);
// Original: arm9/ov031 @ 0x02238DA0; symbol: func_ov031_02238da0; size: 0x14.
extern "C" void System_SetModeSixAndRefresh(void) {
    func_ov031_02239108(6);
    func_ov027_021dcd20();
}
