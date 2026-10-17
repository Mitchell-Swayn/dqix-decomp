#include <globaldefs.h>
ARM
extern "C" int func_ov004_0215e47c(void* object, unsigned value);
extern "C" void Graphics_OffsetSelectedVectorAngle(int result, void* object);
extern "C" void func_ov023_021f66f4(void* object, unsigned value, unsigned enabled);
// Original: arm9/ov004 @ 0x02162ACC; symbol: func_ov004_02162acc; size: 0x38.
extern "C" int Graphics_ApplyConditionalObjectTransition(void* object) {
    int result = func_ov004_0215e47c(object, 0x82);
    if (result) {
        Graphics_OffsetSelectedVectorAngle(result, object);
        func_ov023_021f66f4(object, 0x86, 1);
    }
    return 0;
}
