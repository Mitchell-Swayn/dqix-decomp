#include <globaldefs.h>
ARM
extern "C" void Script_SetBrightnessByMode(unsigned mode, void *first, void *second);
// Original: arm9/ov001 @ 0x0215B6A0; symbol: func_ov001_0215b6a0; size: 0x1C.
extern "C" int GameState_CreateFlaggedRecord(void *first, void *second) {
    Script_SetBrightnessByMode(13, first, second);
    return 1;
}
