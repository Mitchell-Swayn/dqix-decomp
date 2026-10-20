#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void* parameter);
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_ReadPResources(void* state);
extern "C" void _Z17SetMainBrightnessP13GameResourcesii(void*, int, int);
extern "C" void* GameResources_GetInstance();
// Original: arm9/ov001 @ 0x0215B4C0; symbol: func_ov001_0215b4c0; size: 0x4C.
extern "C" int Script_SetMainBrightness(void* parameters, int parameterCount) {
    int brightness = Script_ReadParameterAsInteger(parameters);
    if (parameterCount >= 2) Script_ReadParameterAsInteger((char*)parameters + 8);
    void* resources = GameState_ReadPResources(_ZN9GameState11GetInstanceEv());
    if (resources != 0) {
        _Z17SetMainBrightnessP13GameResourcesii(resources, 0, brightness);
        GameResources_GetInstance();
    }
    return 1;
}
