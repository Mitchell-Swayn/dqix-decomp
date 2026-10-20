// SDK support (community reconstruction): MTX_Identity43_.
#pragma thumb off
// SDK support (community reconstruction): MTX_Identity43_.
// Labelled SDK community assembly; excluded from C/C++ reconstruction credit.
// Source: pret/pokeheartgold @ 14c48938174ec92563afc6d03de5fa162f4cfdce
// lib/NitroSDK/asm/fx_mtx43.s, MTX_Identity43_.
// Original: arm9/main @ 0x020C1840; symbol: Mat4x3_WriteIdentity; size: 0x28.
// Writes the 4x3 fixed-point identity matrix with diagonal values 0x1000.
// Reference instructions verbatim; existing exported ABI spelling preserved.
extern "C" asm void MTX_Identity43_(register void *matrix)
{
	mov r2, #0x1000
	mov r3, #0
	stmia r0!, {r2, r3}
	mov r1, #0
	stmia r0!, {r1, r3}
	stmia r0!, {r2, r3}
	stmia r0!, {r1, r3}
	stmia r0!, {r2, r3}
	stmia r0!, {r1, r3}
	bx lr
}
