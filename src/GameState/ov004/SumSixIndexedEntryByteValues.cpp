#include <globaldefs.h>
ARM
extern "C" void *data_ov004_021707c0;
extern "C" void *Util_FindRecordBySignedId(void *, int);
// Original: arm9/ov004 @ 0x02153860; symbol: func_ov004_02153860; size: 0x54.
extern "C" short SumSixIndexedEntryByteValues(void) {
    short sum = 0;
    for (short index = 1; index <= 6; ++index) {
        void *entry = Util_FindRecordBySignedId(data_ov004_021707c0, index);
        if (entry != 0) sum = (short)(sum + *((unsigned char *)entry + 5));
    }
    return sum;
}
