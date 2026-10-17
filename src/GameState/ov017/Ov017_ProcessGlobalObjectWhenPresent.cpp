#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov017_021d83ac[];
extern "C" void func_ov002_02155dbc(void);
// Original: arm9/ov017 @ 0x021A5934; symbol: func_ov017_021a5934; size: 0x20.
extern "C" void Ov017_ProcessGlobalObjectWhenPresent(void) {
    if (*(void **)data_ov017_021d83ac != 0) func_ov002_02155dbc();
}
