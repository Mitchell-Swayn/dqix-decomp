#include <globaldefs.h>
ARM
extern "C" int* WfcUtility_CreatePointerRing(void);
// Original: arm9/ov031 @ 0x0223BEEC; symbol: func_ov031_0223beec; size: 0x40.
extern "C" void WfcUtility_CreateSteppedPointerRing(int count, int firstValue, int step) {
    int* values = WfcUtility_CreatePointerRing();
    int i = 0;
    if (count > 0) {
        do {
            *(values + i + 1) = firstValue;
            i++;
            firstValue += step;
        } while (i < count);
    }
    ((unsigned char*)values)[3] = (unsigned char)count;
}
