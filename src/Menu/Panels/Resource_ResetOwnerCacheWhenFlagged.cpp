#include <globaldefs.h>
ARM
extern "C" void* memset(void*, int, unsigned);
extern "C" void MenuNotice_FormatCenteredTitleAndRevealMask(void*, void*);
extern "C" int Window_ReplaceCanvasTextById(void*, unsigned, void*, unsigned, unsigned char);
struct OwnerFlags { unsigned short bit0:1; unsigned short rest:15; };
// Original: arm9/ov023 @ 0x021ED44C; symbol: func_ov023_021ed44c; size: 0x6C.
extern "C" void Resource_ResetOwnerCacheWhenFlagged(unsigned char* object) {
    if ((*(unsigned short*)(object + 0x438) & 1) == 0) return;
    memset(*(void**)(object + 0x1c), 0, 0x960);
    MenuNotice_FormatCenteredTitleAndRevealMask(object, *(void**)(object + 0x1c));
    Window_ReplaceCanvasTextById(object + 0xc4, 0, *(void**)(object + 0x1c), 0, 1);
    ((OwnerFlags*)(object + 0x438))->bit0 = 0;
}
