#include <globaldefs.h>
ARM
extern "C" void *Menu_FindCanvasNodeByKey(void *);
extern "C" unsigned MenuRecord_GetType(void *);
// Original: arm9/ov004 @ 0x0215E4C0; symbol: func_ov004_0215e4c0; size: 0x28.
extern "C" void *Menu_FindPageIndicatorByKey(void *input) {
    void *result = Menu_FindCanvasNodeByKey(input);
    if (!result)
        return 0;
    if (MenuRecord_GetType(result) != 6)
        result = 0;
    return result;
}
