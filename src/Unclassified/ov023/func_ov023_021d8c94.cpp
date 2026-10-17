#include <globaldefs.h>
ARM
extern "C" void ResetEachIndexedEntryResource(void *);
// Original: arm9/ov023 @ 0x021D8C94; symbol: func_ov023_021d8c94; size: 0x20.
extern "C" void func_ov023_021d8c94(void *object) {
    unsigned char value = *(unsigned char *)((char *)object + 0x11a);
    if (value != 0 && value != 3)
        ResetEachIndexedEntryResource((char *)object + 0x20);
}
