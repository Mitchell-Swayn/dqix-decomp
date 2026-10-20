#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);

// Original: arm9/ov017 @ 0x021AA3F4; symbol: func_ov017_021aa3f4; size: 0x28.
extern "C" void FieldMessage_InitializeHpReducedToOneNotice(signed char *record) {
    LinkedQueue_InitializeNodeStatus(record);
    record[0] = 0x19;
    *(unsigned short *)(record + 8) = 0;
    *(unsigned short *)(record + 0x0a) = 0;
    *(unsigned short *)(record + 0x0c) = 0;
}
