#include <globaldefs.h>
ARM
extern "C" void InitializeThreeStateBytesOnce(void*);
// Original: arm9/ov008 @ 0x02188EF0; symbol: func_ov008_02188ef0; size: 0x6C.
extern "C" void RecordsScreen_BeginRequestedPanelClose(unsigned char* self) {
    unsigned flags = *(unsigned*)(self + 0xb18);
    if ((flags & 0x100000) == 0 || (flags & 0x200000) != 0) return;
    if (*(volatile unsigned char*)(self + 0xb2a) != 0) return;
    void* object = *(void**)(self + 0xb08);
    if (object != 0 && (*(unsigned short*)((char*)object + 0x438) & 4) == 0) InitializeThreeStateBytesOnce(object);
    self[0xb13] = 0;
    self[0xb10] = 0xd;
    self[0xb11] = 0;
    self[0xb2a] += 1;
}
