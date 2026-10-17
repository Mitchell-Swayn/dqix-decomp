#include <globaldefs.h>
ARM
extern unsigned char data_ov023_021fff08[];
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
// Original: arm9/ov023 @ 0x021F55B8; symbol: func_ov023_021f55b8; size: 0x30.
extern "C" int Script_StoreParameterIntToConfiguredHalfword(const void *parameter) {
    if (data_ov023_021fff08[2]) {
        int value = _ZNK6Script9Parameter5ToIntEv(parameter);
        unsigned short *destination = *(unsigned short **)(data_ov023_021fff08 + 0xc);
        *destination = (unsigned short)value;
    }
    return 1;
}
