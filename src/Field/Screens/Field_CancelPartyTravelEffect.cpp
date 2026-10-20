#include <globaldefs.h>
ARM
extern "C" void CleanupDisplayObject(void *);
// Original: arm9/ov017 @ 0x021A72DC; symbol: func_ov017_021a72dc; size: 0x18.
extern "C" unsigned int Field_CancelPartyTravelEffect(void *object) {
    CleanupDisplayObject(object);
    *(unsigned char *)((unsigned char *)object + 1) = 1;
    return 1;
}
