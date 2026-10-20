// SDK support (community reconstruction): MI_Copy36B.
#pragma thumb off
// SDK support (community reconstruction): MI_Copy36B.
// Original: arm9/main @ 0x020CA528; symbol: func_020ca528; size: 0x1C.
// SDK community assembly: MI_Copy36B; no C/C++ reconstruction credit.
// Copies exactly 36 bytes using three groups of three words.
// Reference: build/sdk-identification/reference/lib/NitroSDK/asm/mi_memory.s
// Reference SHA256: 951a8d9cc34621fdf01e22d753fd7a1cb99e35c008385f098e3e4a86a6c71e8d
// Original instruction sequence retained; ip register alias spelled r12.
extern "C" asm void MI_Copy36B(const void* src, void* dst)
{
	ldmia r0!, {r2, r3, r12}
	stmia r1!, {r2, r3, r12}
	ldmia r0!, {r2, r3, r12}
	stmia r1!, {r2, r3, r12}
	ldmia r0!, {r2, r3, r12}
	stmia r1!, {r2, r3, r12}
	bx lr
}
