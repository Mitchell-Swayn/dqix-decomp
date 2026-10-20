#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" void *GameState_GetIndexList(void *);
extern "C" void TextCanvas_ShowDisplayPart(unsigned char *, int);
extern "C" void TextCanvas_SetGroupPalette(char *, int, unsigned char);
extern "C" void TextCanvas_SetEntryNumericValue(char *, int, int);
extern "C" int TextCanvas_CreateAndConfigureDisplayPart(char *, int);
// Original: arm9/ov003 @ 0x02176798; symbol: func_ov003_02176798; size: 0x54.
extern "C" void Shop_RefreshGoldDisplay(void *context) {
    void *indexList = GameState_GetIndexList(_ZN9GameState11GetInstanceEv());
    char *object = *(char **)((char *)context + 0x89c);
    TextCanvas_ShowDisplayPart((unsigned char *)object, 0);
    TextCanvas_SetGroupPalette(object, 0, 0);
    TextCanvas_SetEntryNumericValue(object, 0, *(int *)((char *)indexList + 0xf6c));
    TextCanvas_CreateAndConfigureDisplayPart(object, 0);
}
