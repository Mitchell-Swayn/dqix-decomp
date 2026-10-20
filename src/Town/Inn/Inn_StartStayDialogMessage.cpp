#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void TextWindow_StartFormattedMessage(int, int, int, int);
// Original: arm9/ov003 @ 0x0215CAB0; symbol: func_ov003_0215cab0; size: 0x40.
extern "C" void Inn_StartStayDialogMessage(void *owner, unsigned int selected) {
    if (selected == 0) return;
    void *context = (void *)TextContext_GetSharedInstance();
    TextWindow_StartFormattedMessage((int)context, selected, 0, 0xe3);
    *((unsigned char *)context + 0x1000 + 0x9b2) = *((unsigned char *)owner + 0x3ef);
    *(unsigned int *)((char *)context + 0x99c) = *((unsigned char *)owner + 0x3ee);
}
