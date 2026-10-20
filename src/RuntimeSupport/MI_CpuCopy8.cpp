// SDK support (community reconstruction): MI_CpuCopy8.
// SDK community assembly: MI_CpuCopy8 from pret/pokeheartgold.
// Pinned commit: 14c48938174ec92563afc6d03de5fa162f4cfdce.
// Reference: lib/NitroSDK/asm/mi_memory.s; SHA256: 951a8d9cc34621fdf01e22d753fd7a1cb99e35c008385f098e3e4a86a6c71e8d.
// Original: arm9/main @ 0x020CA650; symbol: VectorizedInvertedMemcpy; size: 0x180.
// ABI: void(const void* source, void* destination, unsigned int length).
// Canonical SDK identity: MI_CpuCopy8. Community source retained verbatim apart from function wrapper.
// SDK assembly support; no C/C++ reconstruction credit.
#pragma thumb off
extern "C" asm void MI_CpuCopy8(const void* source, void* destination, unsigned int length)
{
	cmp r2, #0
	beq _020D4A5C
	b _020D4A60
_020D4A5C:
	bx lr
_020D4A60:
	tst r1, #1
	beq _020D4AB8
	ldrh ip, [r1, #-1]
	and ip, ip, #0xff
	tst r0, #1
	bne _020D4A7C
	b _020D4A80
_020D4A7C:
	ldrh r3, [r0, #-1]
_020D4A80:
	bne _020D4A88
	b _020D4A8C
_020D4A88:
	mov r3, r3, lsr #8
_020D4A8C:
	beq _020D4A94
	b _020D4A98
_020D4A94:
	ldrh r3, [r0]
_020D4A98:
	orr r3, ip, r3, lsl #8
	strh r3, [r1, #-1]
	add r0, r0, #1
	add r1, r1, #1
	subs r2, r2, #1
	beq _020D4AB4
	b _020D4AB8
_020D4AB4:
	bx lr
_020D4AB8:
	eor ip, r1, r0
	tst ip, #1
	beq _020D4B14
	bic r0, r0, #1
	ldrh ip, [r0], #2
	mov r3, ip, lsr #8
	subs r2, r2, #2
	blo _020D4AF0
_020D4AD8:
	ldrh ip, [r0], #2
	orr ip, r3, ip, lsl #8
	strh ip, [r1], #2
	mov r3, ip, lsr #0x10
	subs r2, r2, #2
	bhs _020D4AD8
_020D4AF0:
	tst r2, #1
	beq _020D4AFC
	b _020D4B00
_020D4AFC:
	bx lr
_020D4B00:
	ldrh ip, [r1]
	and ip, ip, #0xff00
	orr ip, ip, r3
	strh ip, [r1]
	bx lr
_020D4B14:
	tst ip, #2
	beq _020D4B40
	bics r3, r2, #1
	beq _020D4BA4
	sub r2, r2, r3
	add ip, r3, r1
_020D4B2C:
	ldrh r3, [r0], #2
	strh r3, [r1], #2
	cmp r1, ip
	blo _020D4B2C
	b _020D4BA4
_020D4B40:
	cmp r2, #2
	blo _020D4BA4
	tst r1, #2
	beq _020D4B68
	ldrh r3, [r0], #2
	strh r3, [r1], #2
	subs r2, r2, #2
	beq _020D4B64
	b _020D4B68
_020D4B64:
	bx lr
_020D4B68:
	bics r3, r2, #3
	beq _020D4B88
	sub r2, r2, r3
	add ip, r3, r1
_020D4B78:
	ldr r3, [r0], #4
	str r3, [r1], #4
	cmp r1, ip
	blo _020D4B78
_020D4B88:
	tst r2, #2
	bne _020D4B94
	b _020D4B98
_020D4B94:
	ldrh r3, [r0], #2
_020D4B98:
	bne _020D4BA0
	b _020D4BA4
_020D4BA0:
	strh r3, [r1], #2
_020D4BA4:
	tst r2, #1
	beq _020D4BB0
	b _020D4BB4
_020D4BB0:
	bx lr
_020D4BB4:
	ldrh r2, [r1]
	ldrh r0, [r0]
	and r2, r2, #0xff00
	and r0, r0, #0xff
	orr r0, r2, r0
	strh r0, [r1]
	bx lr
}
