#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);
// Original: arm9/ov017 @ 0x021C2688; symbol: func_ov017_021c2688; size: 0x24.
extern "C" void Util_InitializeRecordWithMarker44(signed char *record) {
    LinkedQueue_InitializeNodeStatus(record);
    record[0] = 0x44;
    *(int *)(record + 8) = 0;
    record[0xc] = 0;
}
