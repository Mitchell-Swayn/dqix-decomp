#include <globaldefs.h>
ARM
extern "C" void ResetEachIndexedEntryResource(void *);
// Original: arm9/ov023 @ 0x021E76A8; symbol: func_ov023_021e76a8; size: 0x1C.
extern "C" void func_ov023_021e76a8(void *p) {
    if (*(unsigned int *)((unsigned char *)p + 0x5dc))
        ResetEachIndexedEntryResource((unsigned char *)p + 0x78);
}
