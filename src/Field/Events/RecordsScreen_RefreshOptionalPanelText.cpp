#include <globaldefs.h>
ARM
extern "C" void RefreshPackedTextUnlessModeSuppressesIt(unsigned int);
// Original: arm9/ov017 @ 0x021C1220; symbol: Resource_RefreshOwnerFromField1C; size: 0x18.
// Passes the nonzero word at object offset 0x1c to the helper that processes and resets resource records.
extern "C" void RecordsScreen_RefreshOptionalPanelText(void *obj) {
    unsigned int value = *(unsigned int *)((char *)obj + 0x1c);
    if (value) RefreshPackedTextUnlessModeSuppressesIt(value);
}
