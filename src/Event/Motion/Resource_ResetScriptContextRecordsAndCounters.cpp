#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned int);
extern "C" void InitializeIndexedThreePartRecords(void*);
// Original: arm9/ov001 @ 0x02157908; symbol: Resource_ResetScriptContextRecordsAndCounters; size: 0x5C.
// Clears sixteen 12-byte entries, resets counters at +0xC0 and +0xC4, initializes the structure at +0xC8, and clears words +0x464 and +0x468.
extern "C" void Resource_ResetScriptContextRecordsAndCounters(void* self) {
    for (int i = 0; i < 16; ++i)
        memset((char*)self + i * 12, 0, 12);
    *(unsigned*)((char*)self + 0xC0) = 0;
    *(unsigned*)((char*)self + 0xC4) = 0;
    InitializeIndexedThreePartRecords((char*)self + 0xC8);
    *(unsigned*)((char*)self + 0x464) = 0;
    *(unsigned*)((char*)self + 0x468) = 0;
}
