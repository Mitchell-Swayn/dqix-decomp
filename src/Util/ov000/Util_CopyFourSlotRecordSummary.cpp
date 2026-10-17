#include <globaldefs.h>
ARM
extern "C" char* FindFourSlotRecordByIndex(void*,int);
extern "C" unsigned Unclassified_GetPointerAtIndexOrDefaultZero(void*,int);
extern "C" void* ReadIndexedWordAtFixedOffset(void* object, int index);
// Original: arm9/ov000 @ 0x02162C14; symbol: func_ov000_02162c14; size: 0x7C.
extern "C" void Util_CopyFourSlotRecordSummary(char *self, int index, signed char *out) {
    char *record = FindFourSlotRecordByIndex(self + 0x3760, index);
    if (!record) return;
    out[0] = *(signed char*)(record + 0x10 + *(signed char*)(record + 0x18));
    out[1] = *(signed char*)(record + 0x1c);
    out[2] = Unclassified_GetPointerAtIndexOrDefaultZero(self + 0x3760, *(signed char*)(record + 0x1d));
    out[3] = (unsigned)ReadIndexedWordAtFixedOffset(self + 0x3760, *(signed char*)(record + 0x1d));
    *(short*)(out + 6) = *(short*)(record + 0x2c);
    out[4] = *(signed char*)(record + 0x2e);
    *(unsigned short*)(out + 8) = *(unsigned short*)(record + 0x26);
}
