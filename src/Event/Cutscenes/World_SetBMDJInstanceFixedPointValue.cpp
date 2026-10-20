#include <globaldefs.h>
ARM
extern "C" int Script_ReadParameterAsInteger(void*);
extern "C" float Script_ReadParameterAsFloat(void*);
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* _ZN6Zone3D20FindLastBMDJInstanceEii(void*, int, int);
// Original: arm9/ov001 @ 0x02163EF4; symbol: World_SetBMDJInstanceFixedPointValue; size: 0x6C.
// Finds the last BMDJ instance for two integer parameters and writes the third float scaled by 4096 at instance+6.
extern "C" int World_SetBMDJInstanceFixedPointValue(unsigned char* params) {
    int a = Script_ReadParameterAsInteger(params);
    int b = Script_ReadParameterAsInteger(params + 8);
    void* zone = Zone3D_GetMainInstance();
    if (!zone) return 0;
    unsigned char* instance = (unsigned char*)_ZN6Zone3D20FindLastBMDJInstanceEii(zone, a, b);
    if (!instance) return 0;
    float value = Script_ReadParameterAsFloat(params + 16);
    int converted = (int)(value * 4096.0f);
    *(short*)(instance + 6) = converted;
    return 1;
}
