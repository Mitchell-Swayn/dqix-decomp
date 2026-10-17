#include <globaldefs.h>
#pragma optimize_for_size off
extern "C" int Geometry_ReadPositionMatrixStackLevel(unsigned*);
extern "C" int Graphics_ReadStackStatusUnlessBusyFlag(unsigned*);
// Original: arm9/main @ 0x020C537C; symbol: func_020c537c; size: 0x98.
extern "C" ARM void Geometry_ResetMatrixStacksAndIdentities() {
    unsigned projection, texture;
    *(volatile unsigned*)0x04000600 |= 0x8000;
    while (Geometry_ReadPositionMatrixStackLevel(&projection)) {}
    while (Graphics_ReadStackStatusUnlessBusyFlag(&texture)) {}
    volatile unsigned* command = (volatile unsigned*)0x04000440;
    command[0] = 3;
    command[5] = 0;
    command[0] = 0;
    if (texture) command[2] = texture;
    volatile unsigned* identity = (volatile unsigned*)0x04000454;
    identity[0] = 0;
    *(volatile unsigned*)0x04000440 = 2;
    *(volatile unsigned*)0x04000448 = projection;
    identity[0] = 0;
}
