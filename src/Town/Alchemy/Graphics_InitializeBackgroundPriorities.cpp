#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x210a010; symbol: data_0210a010.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 612 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage[];
extern "C" void Graphics_UpdateMainBackgroundScreens(void *, int);
extern "C" void CancelTwoBackgroundTasksAndResetObject(void *);
// Original: arm9/ov006 @ 0x02155480; symbol: func_ov006_02155480; size: 0x88.
extern "C" void Graphics_InitializeBackgroundPriorities(char *self) {
    *(unsigned char *)(self + 0x12bd) = 1;
    *(unsigned *)(RenderConfigSubmitToFifo_UnknownRoleZeroInitializedStorage + 0xa0) = 0xbfff0000;
    volatile unsigned short *background = (volatile unsigned short *)0x04000008;
    background[0] = (background[0] & ~3) | 2;
    background[1] = background[1] & ~3;
    background[2] = (background[2] & ~3) | 1;
    *(unsigned short *)(self + 0xae2) &= ~0x40;
    Graphics_UpdateMainBackgroundScreens(self + 0xae4, 0);
    CancelTwoBackgroundTasksAndResetObject(self);
}
