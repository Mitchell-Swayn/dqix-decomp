#include <globaldefs.h>
ARM
extern "C" void TextCanvas_SetDisplayPartRefreshFlag(void* p,int key,int enabled);
// Original: arm9/ov003 @ 0x0217451C; symbol: func_ov003_0217451c; size: 0x34.
// Enables record bit six for the pending key at 0xFFC and clears that key to -1.
extern "C" void Shop_RefreshPendingDisplayPart(char *p) {
    int key = *(short *)(p + 0xffc);
    if (key < 0) return;
    TextCanvas_SetDisplayPartRefreshFlag(*(void **)(p + 0x89c), key, 1);
    *(short *)(p + 0xffc) = -1;
}
