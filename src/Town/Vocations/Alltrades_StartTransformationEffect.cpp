#include <globaldefs.h>
#include <GameState/GameState.h>

extern "C" void _ZN8Object3D18SetAnimationByNameEPKci(void*, const char*, int);
extern "C" void _ZN8Object3D11DisableFlagEi(void*, int);
// Original data: arm9/ov003 @ 0x217fe16; symbol: data_ov003_0217fe16.
// Source-defined character literal. Text: "0". Original zero separators, trailing bytes and padding remain unchanged.
// Initial values: "0".
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" char AlltradesStartTransformationEffect_Text0;
// Original: arm9/ov003 @ 0x02158A50; symbol: func_ov003_02158a50; size: 0x34.
extern "C" ARM void Alltrades_StartTransformationEffect(void* object) {
    _ZN8Object3D18SetAnimationByNameEPKci((char*)object + 0x280, &AlltradesStartTransformationEffect_Text0, 9);
    _ZN8Object3D11DisableFlagEi((char*)object + 0x280, 0x40000);
    *(int*)((char*)object + 0x32c) = 1;
}
