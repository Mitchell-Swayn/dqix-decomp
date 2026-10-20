#include <globaldefs.h>
ARM
extern "C" void *_ZN9GameState11GetInstanceEv(void);
extern "C" unsigned int _ZNK9GameState12GetTickCountEv(void *);
extern "C" void TextCanvas_AdvanceDisplayState(void *, int);
extern "C" void TextCanvas_CopyVisibleTilemapToLayer(void *);
extern "C" void DrawConfiguredRecordTilemapBorder(void *, int);
// Original: arm9/ov023 @ 0x021F8140; symbol: func_ov023_021f8140; size: 0x50.
extern "C" void Object_UpdateAndDrawPresentRecord(void *object, int value) {
    unsigned char *p = (unsigned char *)object;
    if (p[0xc] & 8) return;
    unsigned int tick = _ZNK9GameState12GetTickCountEv(_ZN9GameState11GetInstanceEv());
    TextCanvas_AdvanceDisplayState(p + 0x20, tick);
    TextCanvas_CopyVisibleTilemapToLayer(p + 0x20);
    if (p[0xe5] & 4) DrawConfiguredRecordTilemapBorder(object, value);
}
