#include <globaldefs.h>
ARM
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void TextWindow_RenderAndTransferDisplayBuffers(unsigned int *, int);
// Original: arm9/ov017 @ 0x021ADC44; symbol: func_ov017_021adc44; size: 0x14.
extern "C" void FieldPartyEffect_TransferSharedTextWindow(void) {
    unsigned int *field = (unsigned int *)TextContext_GetSharedInstance();
    TextWindow_RenderAndTransferDisplayBuffers(field, 0);
}
