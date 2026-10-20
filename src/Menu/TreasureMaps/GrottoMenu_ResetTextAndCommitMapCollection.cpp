#include <globaldefs.h>
ARM
extern "C" void *TextContext_GetSharedInstance(void *);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void *);
extern "C" void TreasureMapMenu_SaveCollectionAndReleaseResources(void *);
// Original: arm9/ov004 @ 0x02165BE4; symbol: func_ov004_02165be4; size: 0x20.
extern "C" int GrottoMenu_ResetTextAndCommitMapCollection(void *object) {
    void *record = TextContext_GetSharedInstance(object);
    TextWindow_ResetGlyphBuffersAndFrameContexts(record);
    TreasureMapMenu_SaveCollectionAndReleaseResources(object);
    return 0;
}
