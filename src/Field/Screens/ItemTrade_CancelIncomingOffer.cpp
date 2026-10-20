#include <globaldefs.h>
ARM
extern "C" void Resource_DestroyAndResetTypeSixtyFiveRecord(void *);
// Original: arm9/ov017 @ 0x021A85BC; symbol: Resource_DestroyTypeSixtyFiveRecordAndSetStatusByte; size: 0x18.
// Resource helper destroys/resets a type-0x65 record, then the wrapper sets object byte +1 to one.
extern "C" int ItemTrade_CancelIncomingOffer(unsigned char *p) {
    Resource_DestroyAndResetTypeSixtyFiveRecord(p);
    p[1] = 1;
    return 1;
}
