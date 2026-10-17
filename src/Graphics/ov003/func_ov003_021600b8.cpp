#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" int GameState_ReadProtagonistObjectIndex(void*);
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void _ZN8Vector3iaSERKS_(void*, const void*);
extern "C" void Object3D_DrawWithTemporaryHeightAndCameraDisplacement(void*, int, int);
// Original: arm9/ov003 @ 0x021600B8; symbol: func_ov003_021600b8; size: 0x7C.
extern "C" void func_ov003_021600b8(void* p) {
    void* gameState = _ZN9GameState11GetInstanceEv();
    if (*(int*)((char*)p + 0x31c) == 0 || *(int*)((char*)p + 0x320) == 0)
        return;
    void* object = GameState_GetObjectWithFlag100(gameState, GameState_ReadProtagonistObjectIndex(gameState));
    if (object == 0)
        return;
    _ZN8Vector3iaSERKS_((char*)*(int*)((char*)p + 0x320) + 0x44, (char*)object + 0x44);
    *(volatile int*)0x04000444 = 0;
    Object3D_DrawWithTemporaryHeightAndCameraDisplacement(*(void**)((char*)p + 0x320), 0, 0);
    *(volatile int*)0x04000448 = 1;
}
