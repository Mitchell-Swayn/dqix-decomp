#include <globaldefs.h>
ARM
// Original: arm9/ov004 @ 0x0215A2F8; symbol: func_ov004_0215a2f8; size: 0x24.
extern "C" void Menu_ResetItemListingSelection(void *record) {
    *(short *)((char *)record + 0x6c) = -1;
    *((char *)record + 0x6e) = 0;
    *((char *)record + 0x6f) = 0;
    *((char *)record + 0x70) = -1;
    *(int *)((char *)record + 0x74) = -1;
    *(int *)((char *)record + 0x78) = 0;
}
