#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void *);
extern "C" void *memset(void *, int, unsigned int);
extern "C" void Graphics_FormatAvailablePartyMemberChoices(void *, void *);
extern "C" int Window_ReplaceCanvasTextById(void *, unsigned int, void *, unsigned int, unsigned char);
// Original: arm9/ov000 @ 0x02177798; symbol: func_ov000_02177798; size: 0x4C.
extern "C" void Owner_ResetCacheAndLoadMatchingRecord(void *owner) {
    void *field = (void *)TextContext_GetSharedInstance(owner);
    void *cache = *(void **)((unsigned char *)field + 0x5C);
    memset(cache, 0, 0x960);
    Graphics_FormatAvailablePartyMemberChoices(owner, cache);
    Window_ReplaceCanvasTextById((unsigned char *)owner + 0x188, 3, cache, 1, 0);
}
