#include <globaldefs.h>
ARM

struct GameState;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned char *GameState_FindIndexedObjectWithFlag400(GameState *, unsigned);
extern "C" void _ZN8Object3D24TransitionInheritedAlphaEii(void *, int, int);
extern "C" void _ZN8Object3D17SetInheritedAlphaEi(void *, int);

// Original: arm9/ov023 @ 0x021ED988; symbol: func_ov023_021ed988; size: 0x70.
extern "C" void Graphics_TransitionIndexedObjectAlpha(void *entries, int alpha) {
    GameState *state = (GameState *)_ZN9GameState11GetInstanceEv();
    unsigned char *base = (unsigned char *)entries;
    for (int i = 0; i < base[0x6E2E]; i++) {
        unsigned short id = *(unsigned short *)(base + 0x6E30 + i * 2);
        void *object = GameState_FindIndexedObjectWithFlag400(state, id);
        if (alpha > 0) {
            _ZN8Object3D24TransitionInheritedAlphaEii(object, 0, alpha);
        } else {
            _ZN8Object3D17SetInheritedAlphaEi(object, 0);
        }
    }
}
