#include <globaldefs.h>
ARM
extern "C" void Graphics_ResetCountedTransferRecordsAtOffset2C(unsigned char *);
extern "C" void ProcessEachE0ByteRecord(unsigned char *);
extern "C" void SetValueZeroForEachThirtyTwoByteEntry(unsigned char *);
// Original: arm9/ov003 @ 0x02167548; symbol: func_ov003_02167548; size: 0x34.
extern "C" void Graphics_CleanupTransferState(unsigned char *p) {
    if (*(unsigned char *)(p + 0x74) == 0 || *(unsigned int *)(p + 0x10) == 0) return;
    Graphics_ResetCountedTransferRecordsAtOffset2C(*(unsigned char **)(p + 0x10));
    ProcessEachE0ByteRecord(*(unsigned char **)(p + 0x10));
    SetValueZeroForEachThirtyTwoByteEntry(*(unsigned char **)(p + 0x10));
}
