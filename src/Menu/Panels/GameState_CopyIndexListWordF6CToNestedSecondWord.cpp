#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *state);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021EA9DC; symbol: GameState_CopyIndexListWordF6CToNestedSecondWord; size: 0x24.
// Copies the index-list word at offset 0xF6C to the nested second word of the output.
extern "C" unsigned int GameState_CopyIndexListWordF6CToNestedSecondWord(void *output) {
    char *list = (char *)GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    Script_WriteIntegerReferenceOutput(output, *(int *)(list + 0xf6c));
    return 1;
}
