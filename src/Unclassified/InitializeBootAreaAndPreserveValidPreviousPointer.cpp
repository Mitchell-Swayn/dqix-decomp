#pragma optimize_for_size off
#pragma opt_common_subs off
#include <globaldefs.h>
struct StartupState { unsigned int previous; unsigned int reserved; unsigned int flag; };
extern "C" StartupState data_02111588;
extern "C" void func_020c8aac();
struct BootArea { char pad[0xfdc]; unsigned int entry; };
// Original: arm9/main @ 0x020C8A3C; symbol: func_020c8a3c; size: 0x70.
extern "C" void InitializeBootAreaAndPreserveValidPreviousPointer() {
    unsigned int* slot = (unsigned int*)0x027ffd9c;
    BootArea* area = (BootArea*)0x027e3000;
    unsigned int value = *slot;
    if (value >= 0x02600000 && value < 0x02800000) data_02111588.previous = value;
    else data_02111588.previous = 0;
    if (!data_02111588.previous) {
        *slot = (unsigned int)&func_020c8aac;
        area->entry = (unsigned int)&func_020c8aac;
    }
    data_02111588.flag = 0;
}
