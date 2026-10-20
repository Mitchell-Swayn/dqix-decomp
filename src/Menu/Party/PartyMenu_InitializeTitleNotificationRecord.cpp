#include <globaldefs.h>
#include <std_library_functions.h>
ARM
#pragma force_active on
// Original: arm9/ov002 @ 0x02168C38; symbol: func_ov002_02168c38; size: 0x70.
// Clears the packed text attributes, fixed header, and 512-byte inline text buffer.
extern "C" void PartyMenu_InitializeTitleNotificationRecord(unsigned int* record) {
    record[0] &= ~0x1ffU;
    record[0] &= 0xfffc01ffU;
    record[0] &= 0xf803ffffU;
    record[0] &= ~0x38000000U;
    record[0] &= ~0xc0000000U;
    record[1] = 0;
    record[2] = 0;
    memset(record + 3, 0, 0x38);
    memset(record + 17, 0, 0x200);
    record[1] = (unsigned int)(record + 17);
}
