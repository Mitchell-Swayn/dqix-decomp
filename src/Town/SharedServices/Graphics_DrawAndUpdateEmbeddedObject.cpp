#include <globaldefs.h>
ARM
extern "C" void _ZN8Object3D4DrawEb(void*, bool);
extern "C" void Town_InvokeFacilityPreviewDraw(void* object);
// Original: arm9/ov003 @ 0x0216D5F0; symbol: func_ov003_0216d5f0; size: 0x4C.
extern "C" void Graphics_DrawAndUpdateEmbeddedObject(void* self) {
    if (*(unsigned char*)((char*)self + 0x13E8))
        _ZN8Object3D4DrawEb((char*)self + 0x133C, true);
    if (*(short*)((char*)self + 4) != 5) return;
    if (*(short*)((char*)self + 6) != 6) return;
    Town_InvokeFacilityPreviewDraw((char*)self + 0xF1C);
}
