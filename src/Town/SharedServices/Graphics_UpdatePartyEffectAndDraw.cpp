#include <globaldefs.h>
ARM
struct Object3D;
extern "C" void* _ZN9GameState11GetInstanceEv(void);
extern "C" Object3D* _ZN9GameState21GetPartyMemberByIndexEi(void*, int);
extern "C" void _ZN8Object3D14AdvanceEffectsEv(Object3D*);
extern "C" void _ZN8Object3D4DrawEb(Object3D*, bool);
extern "C" void Object3D_CopyPosition(char*, int*);
// Original: arm9/ov003 @ 0x02154F80; symbol: func_ov003_02154f80; size: 0x50.
extern "C" void Graphics_UpdatePartyEffectAndDraw(unsigned char* object) {
    if (!*(unsigned*)(object + 0x32c)) return;
    Object3D* member = _ZN9GameState21GetPartyMemberByIndexEi(_ZN9GameState11GetInstanceEv(), (signed char)object[0x1f7]);
    if (member) Object3D_CopyPosition((char*)object + 0x280, (int*)((char*)member + 0x44));
    Object3D* drawable = (Object3D*)(object + 0x280);
    _ZN8Object3D14AdvanceEffectsEv(drawable);
    _ZN8Object3D4DrawEb(drawable, true);
}
