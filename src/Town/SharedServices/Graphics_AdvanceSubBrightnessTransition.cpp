#include <globaldefs.h>
ARM
extern "C" void* GameResources_GetInstance();
extern "C" void _Z16SetSubBrightnessP13GameResourcesii(void*, int, int);
extern "C" int _Z31IsSubBrightnessTransitionActiveP13GameResources(void*);
// Original: arm9/ov003 @ 0x02173AF4; symbol: func_ov003_02173af4; size: 0x54.
extern "C" void Graphics_AdvanceSubBrightnessTransition(void* self) {
    void* resources = GameResources_GetInstance();
    unsigned char state = *(unsigned char*)((char*)self + 0xEF);
    if (state == 0) {
        _Z16SetSubBrightnessP13GameResourcesii(resources, -16, 24);
        *(unsigned char*)((char*)self + 0xEF) = 1;
        return;
    }
    if (state != 1) return;
    if (!_Z31IsSubBrightnessTransitionActiveP13GameResources(resources)) {
        *(unsigned char*)((char*)self + 0xED) = 6;
        *(unsigned char*)((char*)self + 0xEF) = 0;
    }
}
