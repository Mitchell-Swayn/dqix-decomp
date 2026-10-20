#include <globaldefs.h>
ARM
extern "C" void *memset(void *, int, unsigned int);
extern "C" void Graphics_FormatFiveRowSelectionText(unsigned char *, char *);
extern "C" int Window_ReplaceCanvasTextById(void *, unsigned int, void *, unsigned int, unsigned char);
// Original: arm9/ov013 @ 0x02186BD4; symbol: func_ov013_02186bd4; size: 0x48.
extern "C" void Graphics_FormatFiveRowSelectionTextAndRefreshOwner(void *p) {
    memset(*(void **)((char *)p + 0x658), 0, 0x960);
    Graphics_FormatFiveRowSelectionText((unsigned char *)p, *(char **)((char *)p + 0x658));
    Window_ReplaceCanvasTextById((char *)p + 0x38, 0, *(void **)((char *)p + 0x658), 1, 0);
}
