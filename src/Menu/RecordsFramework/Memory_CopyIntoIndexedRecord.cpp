#include <globaldefs.h>
ARM
extern "C" void MI_CpuCopy8(const void*, void*, unsigned int);
// Original: arm9/ov023 @ 0x021F6E90; symbol: func_ov023_021f6e90; size: 0x28.
extern "C" void Memory_CopyIntoIndexedRecord(char* base, int index, const void* src) { if (index < 3) MI_CpuCopy8(src, base + 0x30 + index * 0x16, 0x16); }
