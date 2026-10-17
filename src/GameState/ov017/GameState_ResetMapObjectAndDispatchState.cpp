#include <globaldefs.h>
ARM
struct MapGameObject; struct Object;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" MapGameObject* _ZN9GameState20GetUnknownGameObjectEv(void*);
extern "C" void Object_ClearTwoStateFieldsAndOptionallyResetAnimation(Object *p,int reset);
class StateObject { public: int a,b,state; typedef int (StateObject::*Handler)(); };
extern "C" unsigned data_ov017_021d83f0;
extern "C" StateObject::Handler data_020e6d5c;
extern "C" StateObject::Handler data_ov017_021d79e0[];
// Original: arm9/ov017 @ 0x021B228C; symbol: func_ov017_021b228c; size: 0x9C.
extern "C" void GameState_ResetMapObjectAndDispatchState(StateObject *self) {
    MapGameObject *object = _ZN9GameState20GetUnknownGameObjectEv(_ZN9GameState11GetInstanceEv());
    if (object) Object_ClearTwoStateFieldsAndOptionallyResetAnimation((Object*)object, 1);
    if (!(data_ov017_021d83f0 & 1)) {
        data_ov017_021d79e0[8] = data_020e6d5c;
        data_ov017_021d83f0 |= 1;
    }
    if (data_ov017_021d79e0[self->state])
        self->state = (self->*data_ov017_021d79e0[self->state])();
}
