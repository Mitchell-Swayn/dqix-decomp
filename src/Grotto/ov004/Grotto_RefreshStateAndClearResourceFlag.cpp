#include <globaldefs.h>
ARM
struct GameResources;
extern "C" void ComputeGrottoAndContextDependentStateFlags(int mode);
extern "C" GameResources *GameResources_GetInstance(void);
extern "C" void ClearMaskedByteFlagsAtOffsetA97(int object, unsigned char mask);
// Original: arm9/ov004 @ 0x0216ACF8; symbol: func_ov004_0216acf8; size: 0x28.
extern "C" int Grotto_RefreshStateAndClearResourceFlag(void) {
    ComputeGrottoAndContextDependentStateFlags(0);
    GameResources *resources = GameResources_GetInstance();
    int object = *(int *)((char *)resources + 0x36d0);
    ClearMaskedByteFlagsAtOffsetA97(object, 1);
    return 0;
}
