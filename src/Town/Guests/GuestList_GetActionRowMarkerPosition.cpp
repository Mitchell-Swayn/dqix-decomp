#include <globaldefs.h>
ARM
// Original: arm9/ov003 @ 0x021705D4; symbol: Resource_DecodeRecordFiveIndexOutputs; size: 0x68.
// For record type 5, rejects an out-of-range signed index only when flag bit 2 is set; otherwise outputs halfword 4 and index*16+0x2b. All failure paths clear both outputs.
extern "C" void GuestList_GetActionRowMarkerPosition(void *record, unsigned short *first, unsigned short *second) {
    if (*(signed char *)((unsigned char *)record + 1) != 5) goto wrong_type;
    if (*(unsigned short *)((unsigned char *)record + 0x20) & 4) {
        signed char index = *(signed char *)((unsigned char *)record + 6);
        if (index < 0 || index > 3) goto invalid_index;
    }
    *first = 4;
    *second = (unsigned short)(*(signed char *)((unsigned char *)record + 6) * 16 + 0x2b);
    return;
invalid_index:
    *first = 0;
    *second = 0;
    return;
wrong_type:
    *first = 0;
    *second = 0;
}
