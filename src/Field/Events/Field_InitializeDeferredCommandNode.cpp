#include <globaldefs.h>
ARM
extern "C" void LinkedQueue_InitializeNodeStatus(signed char *);

// Original: arm9/ov017 @ 0x021C16A8; symbol: InitializeRecordWithByte30AndClearBytes8And9; size: 0x24.
// Initializes four words with invalid indices, stores byte 0x30, and clears bytes 8 and 9.
extern "C" void Field_InitializeDeferredCommandNode(signed char *record) {
    LinkedQueue_InitializeNodeStatus(record);
    record[0] = 0x30;
    record[8] = 0;
    record[9] = 0;
}
