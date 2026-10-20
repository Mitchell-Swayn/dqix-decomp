#include <globaldefs.h>
ARM
extern "C" void Resource_ResetIndexedEntriesWhenEnabled(unsigned int);
// Original: arm9/ov017 @ 0x021BAE98; symbol: Resource_ResetIndexedEntriesFromField20; size: 0x18.
// Passes the nonzero word at object offset 0x20 to Resource_ResetIndexedEntriesWhenEnabled.
extern "C" void Field_ResetOverlayThreePanelRenderEntries(void *obj) {
    unsigned int value = *(unsigned int *)((char *)obj + 0x20);
    if (value) Resource_ResetIndexedEntriesWhenEnabled(value);
}
