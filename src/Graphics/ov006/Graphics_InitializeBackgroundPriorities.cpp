#include <globaldefs.h>
ARM
extern "C" char data_0210a010[];
extern "C" void Graphics_UpdateMainBackgroundScreens(void *, int);
extern "C" void CancelTwoBackgroundTasksAndResetObject(void *);
// Original: arm9/ov006 @ 0x02155480; symbol: func_ov006_02155480; size: 0x88.
extern "C" void Graphics_InitializeBackgroundPriorities(char *self) {
    *(unsigned char *)(self + 0x12bd) = 1;
    *(unsigned *)(data_0210a010 + 0xa0) = 0xbfff0000;
    volatile unsigned short *background = (volatile unsigned short *)0x04000008;
    background[0] = (background[0] & ~3) | 2;
    background[1] = background[1] & ~3;
    background[2] = (background[2] & ~3) | 1;
    *(unsigned short *)(self + 0xae2) &= ~0x40;
    Graphics_UpdateMainBackgroundScreens(self + 0xae4, 0);
    CancelTwoBackgroundTasksAndResetObject(self);
}
