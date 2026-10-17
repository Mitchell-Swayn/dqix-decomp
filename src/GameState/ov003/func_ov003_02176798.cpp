#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
extern "C" void ClearResolvedEntryByteC5Bit20(unsigned char *, int);
extern "C" void Object_SetGroupNibbleAndTextureLowFourBits(char *, int, unsigned char);
extern "C" void Object_SetSelectedPartInitialWord(char *, int, int);
extern "C" int Object_CreateAndConfigureSelectedDisplayPart(char *, int);
// Original: arm9/ov003 @ 0x02176798; symbol: func_ov003_02176798; size: 0x54.
extern "C" void func_ov003_02176798(void *context) {
    void *indexList = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    char *object = *(char **)((char *)context + 0x89c);
    ClearResolvedEntryByteC5Bit20((unsigned char *)object, 0);
    Object_SetGroupNibbleAndTextureLowFourBits(object, 0, 0);
    Object_SetSelectedPartInitialWord(object, 0, *(int *)((char *)indexList + 0xf6c));
    Object_CreateAndConfigureSelectedDisplayPart(object, 0);
}
