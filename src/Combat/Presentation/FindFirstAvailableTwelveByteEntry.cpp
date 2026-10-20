#include <globaldefs.h>
ARM
extern "C" void *Memory_InitializeRecordSentinel(void *);
// Original: arm9/ov025 @ 0x021EB3E0; symbol: func_ov025_021eb3e0; size: 0x4C.
extern "C" void *FindFirstAvailableTwelveByteEntry(void *self) {
    unsigned char *entry = (unsigned char *)self + 0x594;
    for (unsigned char i = 0; i < 4; ++i, entry += 0xc) {
        if (entry[9] == 0) { Memory_InitializeRecordSentinel(entry); return entry; }
    }
    return 0;
}
