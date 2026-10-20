#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x02155E14; symbol: GetRecordAddressByOneBasedIndex; size: 0x24.
// Returns null outside one-based indices 1 through 12; otherwise returns the corresponding 16-byte-stride record address.
extern "C" void *Alltrades_GetVocationEquipmentRecord(void *base, int index) {
    if (index <= 0 || index >= 13)
        return 0;
    return (char *)base + (index - 1) * 16;
}
