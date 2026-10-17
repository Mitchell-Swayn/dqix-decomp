#include <globaldefs.h>
ARM
extern "C" void* volatile data_ov031_02250c00;
extern "C" void func_ov031_02226910(int, int);
// Original: arm9/ov031 @ 0x022264C8; symbol: func_ov031_022264c8; size: 0x4C.
extern "C" void Overlay_UpdateSharedSignedStateIfChanged(int value) {
    if (value == *(signed char*)((char*)data_ov031_02250c00 + 0x62)) return;
    func_ov031_02226910(value, 1);
    func_ov031_02226910(*(signed char*)((char*)data_ov031_02250c00 + 0x62), 0);
    *((unsigned char*)data_ov031_02250c00 + 0x62) = (unsigned char)value;
}
