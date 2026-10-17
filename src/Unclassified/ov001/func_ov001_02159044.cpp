#include <globaldefs.h>
ARM
extern "C" unsigned int *func_ov001_02158dcc(void);
// Original: arm9/ov001 @ 0x02159044; symbol: func_ov001_02159044; size: 0x18.
extern "C" void func_ov001_02159044(void) {
    unsigned int *p = func_ov001_02158dcc();
    if (p) *p = 6;
}
