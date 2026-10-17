// SDK support (community reconstruction): MIi_UncompressBackward.
// SDK support (community assembly): NitroSDK MIi_UncompressBackward.
// Original: arm9/main @ 0x02000970; symbol: func_02000970; size: 0xAC.
// Reference: pret/pokeheartgold@9d8b7591f09b65804da2fb2dfd56f320633e0d36
// lib/asm/crt0.s, MIi_UncompressBackward. No C/C++ credit.
// Decompresses backward LZ data in place and maintains instruction/data caches.
#pragma thumb off
extern "C" asm void MIi_UncompressBackward(void* compressedEnd)
{
	cmp r0, #0
	beq _02000A18
	stmdb sp!, {r4, r5, r6, r7}
	ldmdb r0, {r1, r2}
	add r2, r0, r2
	sub r3, r0, r1, lsr #24
	bic r1, r1, #0xff000000
	sub r1, r0, r1
	mov r4, r2
_02000994:
	cmp r3, r1
	ble _020009F4
	ldrb r5, [r3, #-1]!
	mov r6, #8
_020009A4:
	subs r6, r6, #1
	blt _02000994
	tst r5, #0x80
	bne _020009C0
	ldrb r0, [r3, #-1]!
	strb r0, [r2, #-1]!
	b _020009E8
_020009C0:
	ldrb ip, [r3, #-1]!
	ldrb r7, [r3, #-1]!
	orr r7, r7, ip, lsl #8
	bic r7, r7, #0xf000
	add r7, r7, #2
	add ip, ip, #0x20
_020009D8:
	ldrb r0, [r2, r7]
	strb r0, [r2, #-1]!
	subs ip, ip, #0x10
	bge _020009D8
_020009E8:
	cmp r3, r1
	mov r5, r5, lsl #1
	bgt _020009A4
_020009F4:
	mov r0, #0
	bic r3, r1, #0x1f
_020009FC:
	mcr p15, 0, r0, c7, c10, 4
	mcr p15, 0, r3, c7, c5, 1
	mcr p15, 0, r3, c7, c14, 1
	add r3, r3, #0x20
	cmp r3, r4
	blt _020009FC
	ldmia sp!, {r4, r5, r6, r7}
_02000A18:
	bx lr
	
}
