#include <globaldefs.h>
ARM
extern "C" void* Zone3D_GetMainInstance();
extern "C" void* _ZN6Zone3D20FindLastBMDJInstanceEii(void*, int, int);
// Original: arm9/ov017 @ 0x021BF5F4; symbol: func_ov017_021bf5f4; size: 0x34.
extern "C" int World_HasBMDJInstanceForObject(void* object) {
    void* zone = Zone3D_GetMainInstance();
    void* position = *(void**)((char*)object + 0xC);
    unsigned short x = *(unsigned short*)((char*)position + 0x2C);
    unsigned short y = *(unsigned short*)((char*)position + 0x2E);
    void* instance = _ZN6Zone3D20FindLastBMDJInstanceEii(zone, x, y);
    return instance && *(void**)((char*)instance + 0x54);
}
