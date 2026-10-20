#include <globaldefs.h>
ARM
extern "C" void ProfileMenu_RestoreScenePresentation(void);
extern "C" void ComputeGrottoAndContextDependentStateFlags(int);
extern "C" unsigned int TextContext_GetSharedInstance(void);
extern "C" void TextWindow_ResetGlyphBuffersAndFrameContexts(void *);
// Original: arm9/ov004 @ 0x0216AA10; symbol: func_ov004_0216aa10; size: 0x60.
extern "C" int Menu_RestoreDisplayAndRefreshWorldContext(void) {
    ProfileMenu_RestoreScenePresentation();
    volatile unsigned short *registers = (volatile unsigned short *)0x04001008;
    registers[0] = (registers[0] & ~3) | 1;
    registers[1] = (registers[1] & ~3) | 2;
    registers[2] &= ~3;
    ComputeGrottoAndContextDependentStateFlags(0);
    void *context = (void *)TextContext_GetSharedInstance();
    if (*(unsigned int *)((char *)context + 0x998) != 0) TextWindow_ResetGlyphBuffersAndFrameContexts(context);
    return 0;
}
