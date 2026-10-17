// SDK support (community reconstruction): MTX_RotZ33_.
// SDK support (community reconstruction): NitroSDK MTX_RotZ33_.
// Reference: pret/pokediamond @ b623abef1b4dfe204ca50aab42447ac00c134290,
// arm9/lib/NitroSDK/src/FX_mtx33.c. Community source, not a vendor object.
#include <globaldefs.h>
#include "System/Matrix.h"
THUMB
// Original: arm9/main @ 0x020C129C; symbol: Mat3x3_WriteRotationZ; size: 0x18.
// Writes the row-vector fixed-point matrix for rotation about the Z axis.
extern "C" asm void MTX_RotZ33_(Matrix3x3* output, fix32_t sine, fix32_t cosine)
{
    stmia r0!, {r2}
    mov r3, #0
    stmia r0!, {r1, r3}
    neg r1, r1
    stmia r0!, {r1-r2}
    mov r1, #1
    lsl r1, r1, #12
    str r3, [r0, #0]
    str r3, [r0, #4]
    str r3, [r0, #8]
    str r1, [r0, #12]
    bx lr
}
