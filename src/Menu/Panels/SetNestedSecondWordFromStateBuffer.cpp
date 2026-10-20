#include <globaldefs.h>
ARM
extern "C" bool GameState_CopyStatisticsRecord(void*);
extern "C" void Script_WriteIntegerReferenceOutput(void*, int);
// Original: arm9/ov023 @ 0x021E9F64; symbol: func_ov023_021e9f64; size: 0x38.
extern "C" int SetNestedSecondWordFromStateBuffer(void* out) {
    unsigned char state[0xb0];
    GameState_CopyStatisticsRecord(state);
    unsigned value = *(unsigned*)(state + 0x44);
    if (value > 0x7fffffffU) value = 0x7fffffffU;
    Script_WriteIntegerReferenceOutput(out, (int)value);
    return 1;
}
