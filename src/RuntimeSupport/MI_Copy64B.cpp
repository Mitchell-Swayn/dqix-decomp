// SDK support (community reconstruction): MI_Copy64B.
// SDK authored assembly reference; no C/C++ reconstruction credit.
// Original: arm9/main @ 0x020CA568; symbol: func_020ca568; size: 0x2C.
// Copies exactly 64 bytes. Instruction body retained verbatim.
// Reference: ntrtwl/NitroSDK@9eec6c92c9d7bba9350732b11296ed16aab3a8bc libraries/mi/src/mi_memory.c:352-365.
#pragma thumb off
extern "C" asm void MI_Copy64B(register const void* source, register void* destination)
{
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0 !, {r2, r3, r12}
    stmia r1 !, {r2, r3, r12}
    ldmia r0, {r0, r2, r3, r12}
    stmia r1 !, {r0, r2, r3, r12}
    bx lr
}
