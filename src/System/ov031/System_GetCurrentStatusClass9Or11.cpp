#include <globaldefs.h>
ARM
extern "C" int func_ov031_02206d90(void);
extern "C" int func_ov031_022077c0(void);
// Original: arm9/ov031 @ 0x022154F8; symbol: func_ov031_022154f8; size: 0x30.
extern "C" int System_GetCurrentStatusClass9Or11(void) {
    if (func_ov031_02206d90() != 0)
        return 11;
    int status = func_ov031_022077c0();
    if (status == 0 || status == -39)
        return 9;
    return 11;
}
