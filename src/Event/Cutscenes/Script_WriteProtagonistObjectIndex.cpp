#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" int GameState_ReadProtagonistObjectIndex(void *state);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov001 @ 0x0215EF20; symbol: func_ov001_0215ef20; size: 0x24.
extern "C" unsigned Script_WriteProtagonistObjectIndex(void *output) {
    int index = GameState_ReadProtagonistObjectIndex(_ZN9GameState11GetInstanceEv());
    Script_WriteIntegerReferenceOutput(output, index);
    return 1;
}
