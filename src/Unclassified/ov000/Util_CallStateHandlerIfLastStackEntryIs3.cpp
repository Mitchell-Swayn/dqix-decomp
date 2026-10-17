#include <globaldefs.h>
ARM
extern "C" int ReadLastGlobalStackEntryOrMinusOne(void);
extern "C" void func_ov026_021dbf04(char *state);
// Original: arm9/ov000 @ 0x02163D94; symbol: func_ov000_02163d94; size: 0x20.
extern "C" void Util_CallStateHandlerIfLastStackEntryIs3(char *state) {
    if (ReadLastGlobalStackEntryOrMinusOne() == 3)
        func_ov026_021dbf04(state);
}
