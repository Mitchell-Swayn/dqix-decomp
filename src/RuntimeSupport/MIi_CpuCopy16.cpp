// SDK support (community reconstruction): NitroSDK MIi_CpuCopy16.
// Original: arm9/main @ 0x020CA3B8; symbol: func_020ca3b8; size: 0x34.
// Reference: pret/pokeheartgold@14c48938174ec92563afc6d03de5fa162f4cfdce lib/NitroSDK/asm/mi_memory.s
#pragma thumb off
extern "C" asm void MIi_CpuCopy16()
{
	mov ip, #0
copy16_47BC:
	cmp ip, r2
	blt copy16_47C8
	b copy16_47CC
copy16_47C8:
	ldrh r3, [r0, ip]
copy16_47CC:
	blt copy16_47D4
	b copy16_47D8
copy16_47D4:
	strh r3, [r1, ip]
copy16_47D8:
	blt copy16_47E0
	b copy16_47E4
copy16_47E0:
	add ip, ip, #2
copy16_47E4:
	blt copy16_47BC
	bx lr
	}
