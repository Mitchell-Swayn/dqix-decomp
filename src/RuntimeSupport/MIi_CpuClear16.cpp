// SDK support (community reconstruction): MIi_CpuClear16.
// SDK support (community reconstruction): NitroSDK MIi_CpuClear16.
// Original: arm9/main @ 0x020CA390; symbol: func_020ca390; size: 0x28.
// Reference: pret/pokeheartgold@14c48938174ec92563afc6d03de5fa162f4cfdce lib/NitroSDK/asm/mi_memory.s, lines 7-24.
// Assembly adaptation: local labels renamed; original ABI retained until integration.
#pragma thumb off
extern "C" asm void MIi_CpuClear16()
{
	mov r3, #0
clear16_4794:
	cmp r3, r2
	blt clear16_47A0
	b clear16_47A4
clear16_47A0:
	strh r0, [r1, r3]
clear16_47A4:
	blt clear16_47AC
	b clear16_47B0
clear16_47AC:
	add r3, r3, #2
clear16_47B0:
	blt clear16_4794
	bx lr
}
