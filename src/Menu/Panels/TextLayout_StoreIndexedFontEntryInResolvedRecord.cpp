#include <globaldefs.h>
ARM
extern "C" void *Menu_ResolveFirstLayoutCellForGroup(void *, void *);
extern "C" char *TextLayout_GetThirtyTwoByteFontEntry(int index);
// Original: arm9/ov023 @ 0x021E2550; symbol: TextLayout_StoreIndexedFontEntryInResolvedRecord; size: 0x2C.
// Resolves a record from the first two arguments, looks up the indexed font entry, and stores it at record offset +0xC when found.
extern "C" void TextLayout_StoreIndexedFontEntryInResolvedRecord(void *a, void *b, unsigned index) {
    char *record = (char *)Menu_ResolveFirstLayoutCellForGroup(a, b);
    if (!record)
        return;
    unsigned slot = (index * 4 + 0x28) & 0xff;
    *(char **)(record + 0xc) = TextLayout_GetThirtyTwoByteFontEntry(slot);
}
