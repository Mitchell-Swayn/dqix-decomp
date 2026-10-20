#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" void TextCanvas_CopyVisibleTilemapToLayer(void *);
// Original: arm9/main @ 0x0205D228; symbol: func_0205d228; size: 0x4C.
extern "C" void ProcessAllTwoHundredTwentyFourByteRecordsWhenBothPointersSet(void *object) {
    if (!*(void **)((char *)object + 0x98) || !*(void **)((char *)object + 0x9c)) return;
    unsigned char i;
    for (i = 0; i < *((unsigned char *)object + 0xb3); i++)
        TextCanvas_CopyVisibleTilemapToLayer((char *)*(void **)((char *)object + 0x9c) + i * 0xe0);
}
