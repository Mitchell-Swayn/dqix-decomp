#include <globaldefs.h>
ARM
struct State { char pad[32]; int dirty; int value; };
struct Owner { char pad[36]; State *state; };
struct Message { int pad[2]; int kind; int value; };
extern "C" Owner *data_ov031_0224e580;
// Original: arm9/ov031 @ 0x0220FF78; symbol: func_ov031_0220ff78; size: 0x80.
extern "C" int HandleStateValueMessage(Message *message) {
    switch (message->kind) {
    case 201:
        data_ov031_0224e580->state->value = message->value;
        data_ov031_0224e580->state->dirty = 1;
        break;
    case 202:
        if ((unsigned)(message->value - 2) <= 1) {
            data_ov031_0224e580->state->value = 0;
            data_ov031_0224e580->state->dirty = 1;
        }
        break;
    }
    return 1;
}
