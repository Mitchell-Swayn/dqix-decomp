#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" void _ZN8Object3D24MaybeSetRegularAnimationEPKci(void*, const char*, int);
extern "C" void _ZN8Object3D11DisableFlagEi(void*, int);
extern "C" char data_ov003_0217fe16;
// Original: arm9/ov003 @ 0x02158A50; symbol: func_ov003_02158a50; size: 0x34.
extern "C" ARM void Object3D_SetAnimationAndDisableFlag(void* object) {
    _ZN8Object3D24MaybeSetRegularAnimationEPKci((char*)object + 0x280, &data_ov003_0217fe16, 9);
    _ZN8Object3D11DisableFlagEi((char*)object + 0x280, 0x40000);
    *(int*)((char*)object + 0x32c) = 1;
}
