#include <globaldefs.h>
ARM
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" void* GameState_GetObjectWithFlag100(void*, int);
extern "C" void _ZN8Object3D11MakeVisibleEv(void*);
extern "C" void _ZN8Object3D10MakeHiddenEv(void*);
extern "C" void Object_SetNestedOffset13CByte56(int);
extern "C" void ClearIndirectComponentByte56(int);
extern "C" unsigned int ToggleMaskedFlagsAtOffset34(unsigned char*, unsigned int);
// Original: arm9/ov000 @ 0x02163B90; symbol: func_ov000_02163b90; size: 0x7C.
extern "C" void func_ov000_02163b90(void* self, int visible) {
    void* state = _ZN9GameState11GetInstanceEv();
    for (int i = 0; i <= 3; i++) {
        void* object = GameState_GetObjectWithFlag100(state, i);
        if (object != 0 && ToggleMaskedFlagsAtOffset34(*(unsigned char**)((char*)self + 0x2a0), (unsigned char)i) != 0) {
            if (visible != 0) {
                _ZN8Object3D11MakeVisibleEv(object);
                Object_SetNestedOffset13CByte56((int)object);
            } else {
                _ZN8Object3D10MakeHiddenEv(object);
                ClearIndirectComponentByte56((int)object);
            }
        }
    }
}
