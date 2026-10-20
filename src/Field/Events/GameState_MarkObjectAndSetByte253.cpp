#include <globaldefs.h>
ARM
struct MapGameObject;
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" MapGameObject *_ZN9GameState20GetUnknownGameObjectEv(void *);
extern "C" void GameObject_RequestMovementInputEnable(MapGameObject *);
// Original: arm9/ov017 @ 0x021AB67C; symbol: func_ov017_021ab67c; size: 0x1C.
extern "C" void GameState_MarkObjectAndSetByte253(void *a0) {
    *(unsigned char *)((char *)a0 + 1) = 1;
    void *state = _ZN9GameState11GetInstanceEv();
    MapGameObject *object = _ZN9GameState20GetUnknownGameObjectEv(state);
    GameObject_RequestMovementInputEnable(object);
}
