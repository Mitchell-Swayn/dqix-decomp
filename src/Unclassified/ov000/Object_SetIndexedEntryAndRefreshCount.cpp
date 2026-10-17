#include <globaldefs.h>
ARM
extern "C" int Object_CountEntriesWithPositiveHalfword18(unsigned char *base);
// Original: arm9/ov000 @ 0x02171B68; symbol: func_ov000_02171b68; size: 0x34.
extern "C" void Object_SetIndexedEntryAndRefreshCount(unsigned char *base, int index, void *value) {
    if (index < 0 || index >= 16 || value == 0) {
        return;
    }
    *(void **)(base + index * 4 + 0x3F0) = value;
    base[0x86] = (unsigned char)Object_CountEntriesWithPositiveHalfword18(base);
}
