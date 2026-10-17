#include <globaldefs.h>
ARM

// Original: arm9/ov015 @ 0x02190020; symbol: func_ov015_02190020; size: 0x3C.
extern "C" void Resource_SetLinkedEntryState(void* self, unsigned char state) {
    unsigned char mode = *(unsigned char*)((char*)self + 0x1C);
    if (mode != 0 && mode != 1) return;
    if (*(unsigned char*)((char*)self + 0x3C) == state) return;
    unsigned char* data = *(unsigned char**)((char*)self + 0x24);
    *(short*)(data + 0x200 + 0xB2) = -1;
    *(unsigned char*)((char*)self + 0x3C) = state;
    *(unsigned char*)((char*)self + 0x2C) = 1;
}
