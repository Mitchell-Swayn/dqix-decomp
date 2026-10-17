#include <globaldefs.h>
ARM
extern unsigned char data_ov027_021e3424[];
extern "C" int _s32_div_f(int, int);
// Original: arm9/ov027 @ 0x021DD5A4; symbol: func_ov027_021dd5a4; size: 0x30.
extern "C" void Network_SetChildMPMaxSize(int size) {
    int payloadSize = size - 2;
    *(int *)(data_ov027_021e3424 + 8) = payloadSize;
    int slots = _s32_div_f(30, payloadSize);
    *(int *)(data_ov027_021e3424 + 0xc) = slots;
    *(int *)(data_ov027_021e3424 + 0x10) = 30;
}
