#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetDisplayRecordTransferEntries(void *);
// Original: arm9/ov017 @ 0x021C0550; symbol: func_ov017_021c0550; size: 0x18.
extern "C" void Graphics_ResetTransferEntriesAndCleanResources(void *p) {
    void *owner = *(void **)((unsigned char *)p + 0x20);
    if (owner) Graphics_ResetDisplayRecordTransferEntries(owner);
}
