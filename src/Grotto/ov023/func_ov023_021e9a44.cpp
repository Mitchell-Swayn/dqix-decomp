#include <globaldefs.h>
ARM
struct Record { char pad[20]; unsigned a:9; unsigned b:9; unsigned c:11; unsigned rest:3; };
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" unsigned ComputeNonzeroScaledPercentOf944(Record *p);
extern "C" void SetNestedSecondWordForTypeThree(void *, int);
// Original: arm9/ov023 @ 0x021E9A44; symbol: func_ov023_021e9a44; size: 0x34.
extern "C" int func_ov023_021e9a44(void *out) {
    unsigned char state[0xB0];
    GameState_CopyB0ByteStateBufferToOutput(state);
    unsigned percent = ComputeNonzeroScaledPercentOf944((Record *)state);
    SetNestedSecondWordForTypeThree(out, percent);
    return 1;
}
