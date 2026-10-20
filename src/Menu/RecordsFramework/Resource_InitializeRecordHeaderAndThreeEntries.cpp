#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
extern "C" void Memory_Clear22BytesAndSetTwoSentinels(void*);
// Original: arm9/ov023 @ 0x021F672C; symbol: Resource_InitializeRecordHeaderAndThreeEntries; size: 0x5C.
// Initializes the header and sentinels, clears 0x20 bytes, resets fields +0x28/+0x2C, sets halfword +0x2E to one, and initializes three entries at +0x30.
extern "C" void Resource_InitializeRecordHeaderAndThreeEntries(char* p) {
    *(unsigned int*)p = 0;
    *(unsigned int*)(p + 4) = 0xffffffff;
    memset(p + 8, 0, 0x20);
    *(unsigned int*)(p + 0x28) = 0;
    *(unsigned short*)(p + 0x2c) = 0;
    *(unsigned short*)(p + 0x2e) = 1;
    for (int i = 0; i < 3; ++i) Memory_Clear22BytesAndSetTwoSentinels(p + 0x30 + i * 0x16);
}
