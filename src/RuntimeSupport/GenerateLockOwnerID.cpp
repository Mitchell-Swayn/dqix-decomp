// SDK support (community reconstruction): _Z19GenerateLockOwnerIDv.
#pragma thumb off
// SDK support (community reconstruction): _Z19GenerateLockOwnerIDv.
// Original: arm9/main @ 0x020C7080; symbol: _Z19GenerateLockOwnerIDv; size: 0x68.
// NitroSDK community assembly OS_GetLockID; not C reconstruction.
// Pinned source: https://raw.githubusercontent.com/ntrtwl/NitroSDK/9eec6c92c9d7bba9350732b11296ed16aab3a8bc/libraries/os/src/os_spinLock.c
// Only ABI name, type aliases, ARM9 constants, and documented workaround macro adapted.
#define SDK_ARM9
#define SP1P3_BUG_FOR_CONDITIONAL_ASM_INSTRUCTIONS
#define OSi_ANYP_LOCK_ID_FLAG 0x027fffb0
#define OSi_ANYP_LOCK_ID_START 0x40
#define OS_LOCK_ID_ERROR (-3)
typedef int s32;
asm s32 GenerateLockOwnerID (void)
{
    ldr r3, = OSi_ANYP_LOCK_ID_FLAG
    ldr r1, [r3, #0]
#ifdef SDK_ARM9
    clz r2, r1
#else
    mov r2, #0
    mov r0, #0x80000000
_lp1:
    tst r1, r0
    bne _ex1
    add r2, r2, #1
    cmp r2, #32
    beq _ex1
    mov r0, r0, lsr #1
    b _lp1
_ex1:
#endif
    cmp r2, #32
#ifdef SP1P3_BUG_FOR_CONDITIONAL_ASM_INSTRUCTIONS
    bne @movne1
    b @movne2
@movne1:
    mov  r0, #OSi_ANYP_LOCK_ID_START
@movne2:
#else
    movne r0, #OSi_ANYP_LOCK_ID_START
#endif
    bne _1
    add r3, r3, #4
    ldr r1, [r3, #0]
#ifdef SDK_ARM9
    clz r2, r1
#else
    mov r2, #0
    mov r0, #0x80000000
_lp2:
    tst r1, r0
    bne _ex2
    add r2, r2, #1
    cmp r2, #32
    beq _ex2
    mov r0, r0, lsr #1
    b _lp2
_ex2:
#endif
    cmp r2, #32
    ldr r0, = OS_LOCK_ID_ERROR
#ifdef SP1P3_BUG_FOR_CONDITIONAL_ASM_INSTRUCTIONS
    beq @bxeq1
    b @bxeq2
@bxeq1:
    bx lr
@bxeq2:
#else
    bxeq lr
#endif
    mov r0, #OSi_ANYP_LOCK_ID_START + 32
_1:
    add r0, r0, r2
    mov r1, #0x80000000
    mov r1, r1, lsr r2
    ldr r2, [r3, #0]
    bic r2, r2, r1
    str r2, [r3, #0]
    bx lr
}

