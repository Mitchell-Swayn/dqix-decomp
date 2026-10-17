#include <globaldefs.h>
ARM
extern "C" void ResetRecordWithInvalidIndex(void *);
// Original: arm9/ov023 @ 0x021FC408; symbol: func_ov023_021fc408; size: 0x64.
extern "C" int Unclassified_InitializeType19RecordFromArguments(void *self, int unused, int field6, int field8, int value24, int value26, int value28, int value2a, int value2c, int value2e) {
    ResetRecordWithInvalidIndex(self);
    *(short *)((char *)self + 4) = 0x13;
    *(short *)((char *)self + 6) = (short)field6;
    *(short *)((char *)self + 8) = (short)field8;
    *(int *)((char *)self + 0x1C) = 2;
    *(short *)((char *)self + 0x24) = (short)value24;
    *(short *)((char *)self + 0x26) = (short)value26;
    *(short *)((char *)self + 0x28) = (short)value28;
    *(short *)((char *)self + 0x2A) = (short)value2a;
    *(short *)((char *)self + 0x2C) = (short)value2c;
    *(unsigned char *)((char *)self + 0x2E) = (unsigned char)value2e;
    return 1;
}
