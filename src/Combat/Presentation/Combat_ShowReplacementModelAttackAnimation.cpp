#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *_ZN9GameState20GetGameObjectByIndexEi(void *, int);
extern "C" void _ZN8Object3D11MakeVisibleEv(void *);
extern "C" void _ZN8Object3D10MakeHiddenEv(void *);
extern "C" void _ZN8Object3D18SetAnimationByNameEPKci(void *, const char *, int);
extern "C" char Combat_ShowReplacementModelAttackAnimation_TextAttack1A[];
// Original: arm9/ov025 @ 0x021E6910; symbol: func_ov025_021e6910; size: 0x6C.
extern "C" int Combat_ShowReplacementModelAttackAnimation(void *unused, void *state) {
    void *game = _ZN9GameState11GetInstanceEv();
    void *object = _ZN9GameState20GetGameObjectByIndexEi(game, 0xc8);
    if (object == 0) return 1;
    _ZN8Object3D11MakeVisibleEv(object);
    _ZN8Object3D18SetAnimationByNameEPKci(object, Combat_ShowReplacementModelAttackAnimation_TextAttack1A, 1);
    unsigned short index = *(unsigned short *)((char *)*(void **)((char *)state + 0x10) + 0x20);
    void *related = _ZN9GameState20GetGameObjectByIndexEi(game, index * 12 + 0x1c);
    if (related != 0) _ZN8Object3D10MakeHiddenEv(related);
    return 1;
}
