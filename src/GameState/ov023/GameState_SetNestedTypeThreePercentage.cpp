#include <globaldefs.h>
ARM
struct Record;
extern "C" bool GameState_CopyB0ByteStateBufferToOutput(void *out);
extern "C" unsigned Object_ComputeNonzeroPercentageOf232(Record* p);
extern "C" void SetNestedSecondWordForTypeThree(void *,int);
// Original: arm9/ov023 @ 0x021E9A10; symbol: func_ov023_021e9a10; size: 0x34.
extern "C" int GameState_SetNestedTypeThreePercentage(void* object) {
    unsigned char buffer[0xb0];
    GameState_CopyB0ByteStateBufferToOutput(buffer);
    unsigned value = Object_ComputeNonzeroPercentageOf232((Record*)buffer);
    SetNestedSecondWordForTypeThree(object, (int)value);
    return 1;
}
