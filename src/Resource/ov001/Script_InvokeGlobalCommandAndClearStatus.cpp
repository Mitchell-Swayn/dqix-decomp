#include <globaldefs.h>
extern "C" unsigned char data_ov001_021658b8[];
extern "C" unsigned char data_ov001_021658d8[];
extern "C" void func_ov001_021537b0(void*, void*, unsigned, unsigned);
// Original: arm9/ov001 @ 0x0215ACF8; symbol: func_ov001_0215acf8; size: 0x34.
extern "C" void Script_InvokeGlobalCommandAndClearStatus(unsigned first, unsigned second) {
    func_ov001_021537b0(data_ov001_021658d8, *(void**)data_ov001_021658b8, first, second);
    data_ov001_021658b8[0x8c] = 0;
}
