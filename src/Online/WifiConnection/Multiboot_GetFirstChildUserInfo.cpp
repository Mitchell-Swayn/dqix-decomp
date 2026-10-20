#include <globaldefs.h>
ARM
extern "C" void MB_CommGetChildUser(int);

// Original: arm9/ov031 @ 0x0223AB5C; symbol: func_ov031_0223ab5c; size: 0x10.
extern "C" void Multiboot_GetFirstChildUserInfo(void) {
    MB_CommGetChildUser(1);
}
