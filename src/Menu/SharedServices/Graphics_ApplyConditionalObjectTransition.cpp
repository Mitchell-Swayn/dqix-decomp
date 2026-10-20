#include <globaldefs.h>
ARM
extern "C" int Menu_FindCanvasNodeByKey(void* object, unsigned value);
extern "C" void Graphics_OffsetSelectedVectorAngle(int result, void* object);
extern "C" void MenuRecord_SetNegativeDrawOffsetByKey(void* object, unsigned value, unsigned enabled);
// Original: arm9/ov004 @ 0x02162ACC; symbol: func_ov004_02162acc; size: 0x38.
extern "C" int Graphics_ApplyConditionalObjectTransition(void* object) {
    int result = Menu_FindCanvasNodeByKey(object, 0x82);
    if (result) {
        Graphics_OffsetSelectedVectorAngle(result, object);
        MenuRecord_SetNegativeDrawOffsetByKey(object, 0x86, 1);
    }
    return 0;
}
