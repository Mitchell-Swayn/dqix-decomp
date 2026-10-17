// SDK support (community reconstruction): Startup_FillWords.
// Labelled SDK community assembly; excluded from C/C++ reconstruction credit.
// Source: pret/pokeheartgold @ 14c48938174ec92563afc6d03de5fa162f4cfdce
// lib/NitroSDK/asm/mi_memory.s, MIi_CpuClear32. Diamond MI_memory.c also declares asm.
// Original: arm9/main @ 0x02000954; symbol: func_02000954; size: 0x1C.
// Startup-local copy of SDK word fill, used by ARM9 startup before runtime setup.
// Reference instructions/local labels verbatim; existing exported ABI retained.
extern "C" asm void Startup_FillWords(register unsigned value, register void *dest, register unsigned size)
{
	add ip, r1, r2
_020D47F0:
	cmp r1, ip
	blt _020D47FC
	b _020D4800
_020D47FC:
	stmia r1!, {r0}
_020D4800:
	blt _020D47F0
	bx lr
}
