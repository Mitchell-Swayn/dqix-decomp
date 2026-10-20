#include <globaldefs.h>
ARM
extern "C" void MenuRecord_ResetHeader(void*);
extern "C" void _ZN13ZoneState27545ResetEv(void*);
extern "C" void _ZN13SafeAllocator21ResetAllocatorPointerEv(void*);
// Original: arm9/ov023 @ 0x021FBE08; symbol: func_ov023_021fbe08; size: 0x44.
extern "C" int MenuZone_InitializeResourceRecord(void* record, unsigned unused, unsigned short value1, unsigned short value2, unsigned value3) {
    MenuRecord_ResetHeader(record);
    *(unsigned short*)((char*)record + 4) = 0x11;
    *(unsigned short*)((char*)record + 6) = value1;
    *(unsigned short*)((char*)record + 8) = value2;
    _ZN13ZoneState27545ResetEv((char*)record + 0x34);
    *(unsigned*)((char*)record + 0x4c) = value3;
    _ZN13SafeAllocator21ResetAllocatorPointerEv((char*)record + 0x20);
    return 1;
}
