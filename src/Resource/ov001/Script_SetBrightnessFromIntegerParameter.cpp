#include <globaldefs.h>
ARM
struct IntegerParameterView;
extern "C" int ReadScriptParameterAsInteger(IntegerParameterView*);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadPResources(void*);
extern "C" void _Z13SetBrightnessP13GameResourcesii(void*, int, int);
extern "C" void* GameResources_GetInstance();
// Original: arm9/ov001 @ 0x0215B2CC; symbol: func_ov001_0215b2cc; size: 0x4C.
extern "C" int Script_SetBrightnessFromIntegerParameter(IntegerParameterView* parameters, int count) {
    int brightness = ReadScriptParameterAsInteger(parameters);
    if (count >= 2) ReadScriptParameterAsInteger((IntegerParameterView*)((char*)parameters + 8));
    void* resources = GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
    if (resources != 0) {
        _Z13SetBrightnessP13GameResourcesii(resources, 0, brightness);
        GameResources_GetInstance();
    }
    return 1;
}
