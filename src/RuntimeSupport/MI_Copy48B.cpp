// SDK support (community reconstruction): MI_Copy48B.
// Original: arm9/main @ 0x020CA544; symbol: func_020ca544; size: 0x24.
// SDK community assembly: NitroSDK MI_Copy48B, pret/pokediamond
// b623abef1b4dfe204ca50aab42447ac00c134290, arm9/lib/NitroSDK/src/MI_memory.c.
// This function is assembly in the pinned community source.
extern "C" {
asm void MI_Copy48B(register const void *pSrc, register void *pDest)
{
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}
    ldmia r0!, {r2, r3, r12}
    stmia r1!, {r2, r3, r12}

    bx lr
}
}
