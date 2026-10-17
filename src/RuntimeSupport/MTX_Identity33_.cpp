// SDK support (community reconstruction): MTX_Identity33_.
// SDK support (community reconstruction): NitroSDK MTX_Identity33_.
// Original: arm9/main @ 0x020C1180; symbol: Mat3x3_WriteIdentity; size: 0x24.
// Reference: pret/pokeheartgold@14c48938174ec92563afc6d03de5fa162f4cfdce lib/NitroSDK/asm/fx_mtx33.s
// Writes fixed-point 3x3 identity (diagonal 0x1000, remaining elements zero).
// Assembly implementation: excluded from C/C++ reconstruction credit.
#include <System/Matrix.h>
#pragma thumb off
extern "C" asm void MTX_Identity33_(Matrix3x3* out)
{
	mov r2, #0x1000
	str r2, [r0, #0x20]
	mov r3, #0
	stmia r0!, {r2, r3}
	mov r1, #0
	stmia r0!, {r1, r3}
	stmia r0!, {r2, r3}
	stmia r0!, {r1, r3}
	bx lr
}
