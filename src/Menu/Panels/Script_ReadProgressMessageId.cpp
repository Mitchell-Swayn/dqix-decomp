#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int GameState_GetProgressMessageId(void *);
extern "C" void Script_WriteIntegerReferenceOutput(void *, int);
// Original: arm9/ov023 @ 0x021E934C; symbol: GameState_CopyWordAtOffset5CBCToNestedSecondWord; size: 0x24.
// Copies GameState's word at offset 0x5CBC to the nested second word of the output.
extern "C" int Script_ReadProgressMessageId(void *output) {
    unsigned int value = GameState_GetProgressMessageId(_ZN9GameState11GetInstanceEv());
    Script_WriteIntegerReferenceOutput(output, value);
    return 1;
}
