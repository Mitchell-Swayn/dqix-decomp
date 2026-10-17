#include <globaldefs.h>
ARM
extern "C" void Memory_InitializeRecordSentinel(void *);
extern "C" void AddUniqueFourSlotRecord(void *, const void *);
// Original: arm9/ov025 @ 0x021EB42C; symbol: func_ov025_021eb42c; size: 0x40.
extern "C" void func_ov025_021eb42c(void *obj, unsigned short first, unsigned short second) {
    unsigned char args[0xc];
    Memory_InitializeRecordSentinel(args);
    *(unsigned short *)(args + 4) = first;
    *(unsigned short *)(args + 6) = second;
    args[8] = 0;
    AddUniqueFourSlotRecord(obj, args);
}
