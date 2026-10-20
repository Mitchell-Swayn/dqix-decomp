// SDK support (community reconstruction): MIi_CpuCopyFast.
#pragma thumb off
// SDK support (community reconstruction): MIi_CpuCopyFast.
// Original: arm9/main @ 0x020CA4B4; symbol: func_020ca4b4; size: 0x58.
// SDK community assembly: MIi_CpuCopyFast; no C/C++ reconstruction credit.
// Reference: build/sdk-identification/reference/lib/NitroSDK/asm/mi_memory.s
// Reference SHA256: 951a8d9cc34621fdf01e22d753fd7a1cb99e35c008385f098e3e4a86a6c71e8d
// Original assembly retained; local labels and register alias spellings adapted for this translation unit.
extern "C" asm void MIi_CpuCopyFast(const void* src, void* dst, unsigned int size)
{
	stmdb sp!, {r4, r5, r6, r7, r8, r9, r10}
	add r10, r1, r2
	mov r12, r2, lsr #5
	add r12, r1, r12, lsl #5
CopyFast_48C4:
	cmp r1, r12
	blt CopyFast_48D0
	b CopyFast_48D4
CopyFast_48D0:
	ldmia r0!, {r2, r3, r4, r5, r6, r7, r8, r9}
CopyFast_48D4:
	blt CopyFast_48DC
	b CopyFast_48E0
CopyFast_48DC:
	stmia r1!, {r2, r3, r4, r5, r6, r7, r8, r9}
CopyFast_48E0:
	blt CopyFast_48C4
CopyFast_48E4:
	cmp r1, r10
	blt CopyFast_48F0
	b CopyFast_48F4
CopyFast_48F0:
	ldmia r0!, {r2}
CopyFast_48F4:
	blt CopyFast_48FC
	b CopyFast_4900
CopyFast_48FC:
	stmia r1!, {r2}
CopyFast_4900:
	blt CopyFast_48E4
	ldmia sp!, {r4, r5, r6, r7, r8, r9, r10}
	bx lr
}
