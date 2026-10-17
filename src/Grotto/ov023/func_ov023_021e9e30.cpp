#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
struct Field { unsigned char pad[0x28]; unsigned value:12; unsigned rest:20; };
// Original: arm9/ov023 @ 0x021E9E30; symbol: func_ov023_021e9e30; size: 0x34.
extern "C" int func_ov023_021e9e30(void *out) {
    unsigned char state[0xB0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    SetNestedSecondWordForTypeThree(out, ((Field *)state)->value);
    return 1;
}
