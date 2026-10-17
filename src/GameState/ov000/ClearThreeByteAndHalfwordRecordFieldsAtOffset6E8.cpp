#include <globaldefs.h>
ARM
extern "C" void ClearThreeByteAndHalfwordRecordFields(void *);
// Original: arm9/ov000 @ 0x02182A44; symbol: func_ov000_02182a44; size: 0x14.
extern "C" void ClearThreeByteAndHalfwordRecordFieldsAtOffset6E8(void *record) {
    ClearThreeByteAndHalfwordRecordFields((char *)record + 0x6e8);
}
