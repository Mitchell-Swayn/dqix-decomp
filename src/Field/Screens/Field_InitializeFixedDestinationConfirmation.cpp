#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *p);

// Initializes the record header, then sets kind byte 0x39 and clears words 8, 0xC and 0x10.
// Original: arm9/ov017 @ 0x021A942C; symbol: func_ov017_021a942c; size: 0x28.
extern "C" void Field_InitializeFixedDestinationConfirmation(signed char *record)
{
    LinkedQueue_InitializeNodeStatus(record);
    record[0] = 0x39;
    *(int *)(record + 8) = 0;
    *(int *)(record + 0xc) = 0;
    *(int *)(record + 0x10) = 0;
}
