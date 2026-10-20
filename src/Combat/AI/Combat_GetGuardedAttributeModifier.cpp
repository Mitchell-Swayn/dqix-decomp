#include <globaldefs.h>
ARM
struct GameState;
extern "C" void* _ZN9GameState11GetInstanceEv();
extern "C" unsigned char* GameState_FindIndexedObjectWithFlag400(GameState*,unsigned);
extern "C" float Combat_ComputeClampedAttributeModifier(void*,int,int);
struct Input { unsigned short flags, pad; short index; };
struct Nested { char pad[10]; unsigned short low : 12; unsigned short enabled : 1; unsigned short high : 3; };
struct Data { unsigned a,b; unsigned low : 22; unsigned rate : 5; unsigned high : 5; unsigned c; unsigned flags; unsigned d; unsigned low2 : 27; unsigned rate2 : 5; };
// Original: arm9/ov024 @ 0x021F875C; symbol: func_ov024_021f875c; size: 0x80.
extern "C" float Combat_GetGuardedAttributeModifier(void **self, Input *input, Data *data, int mode) {
    GameState *state = (GameState*)_ZN9GameState11GetInstanceEv();
    if (input->flags & 0x400) {
        unsigned char *object = GameState_FindIndexedObjectWithFlag400(state, input->index);
        if (object && *(Nested**)(object + 0x144)) {
            if ((*(Nested**)(object + 0x144))->enabled) {
                if (!(data->flags & 0x1000000)) return 0;
            }
        }
    }
    unsigned rate;
    if (mode == 1) rate = data->rate2;
    else rate = data->rate;
    return Combat_ComputeClampedAttributeModifier(*self, input->index, rate);
}
