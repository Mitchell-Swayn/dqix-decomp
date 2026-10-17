#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView *);
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_ReadPResources(void *);
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void *, int, int);
extern "C" void *GameResources_GetInstance(void);
// Original: arm9/ov001 @ 0x0215B408; symbol: func_ov001_0215b408; size: 0x4C.
extern "C" int func_ov001_0215b408(IntegerParameterView *parameter, int count) {
    int value = ReadScriptParameterAsInteger(parameter);
    if (count >= 2) ReadScriptParameterAsInteger((IntegerParameterView *)((char *)parameter + 8));
    void *resources = GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
    if (resources != 0) {
        _Z16SetSubBrightnessP13GameResourcesii(resources, 0, value);
        GameResources_GetInstance();
    }
    return 1;
}
