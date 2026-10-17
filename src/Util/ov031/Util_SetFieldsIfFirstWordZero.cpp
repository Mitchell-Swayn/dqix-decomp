#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x022400E8; symbol: func_ov031_022400e8; size: 0x1C.
extern "C" int Util_SetFieldsIfFirstWordZero(int a0, int a1, int a2) {
    if (*(int *)a0)
        return 0;
    *(int *)(a0 + 0x1c) = a1;
    *(int *)(a0 + 0x18) = a2;
    return 1;
}
