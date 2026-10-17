// SDK support (community reconstruction): MIi_CpuClearFast.
// SDK community assembly reconstruction; no C/C++ reconstruction credit.
// Original: arm9/main @ 0x020CA458; symbol: func_020ca458; size: 0x5C.
// Fills a destination with repeated 32-bit data, in 32-byte blocks then words.
// Reference: pret/pokeheartgold@14c48938174ec92563afc6d03de5fa162f4cfdce
// lib/NitroSDK/asm/mi_memory.s lines 104-132; instruction body copied verbatim.
#pragma thumb off
extern "C" asm void MIi_CpuClearFast(unsigned int data, void *destination, unsigned int size)
{
	stmdb sp!, {r4, r5, r6, r7, r8, sb}
	add sb, r1, r2
	mov ip, r2, lsr #5
	add ip, r1, ip, lsl #5
	mov r2, r0
	mov r3, r2
	mov r4, r2
	mov r5, r2
	mov r6, r2
	mov r7, r2
	mov r8, r2
_020D4884:
	cmp r1, ip
	blt _020D4890
	b _020D4894
_020D4890:
	stmia r1!, {r0, r2, r3, r4, r5, r6, r7, r8}
_020D4894:
	blt _020D4884
_020D4898:
	cmp r1, sb
	blt _020D48A4
	b _020D48A8
_020D48A4:
	stmia r1!, {r0}
_020D48A8:
	blt _020D4898
	ldmia sp!, {r4, r5, r6, r7, r8, sb}
	bx lr
}
