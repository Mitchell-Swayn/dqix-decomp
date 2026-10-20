// Compiler runtime support: _Z15__PopStackFrameP12ThrowContextP13ExceptionInfo.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Runtime/Runtime_ARM/Runtime_NITRO/Lib/NITRO_Runtime_Ai_LE.a. Object: exceptionhandler.
// Original vendor source: not recorded in object.
// DQIX USA arm9/main: 0x0200F1A0, 92 bytes.
// Original bytes SHA256: 6f080e9446ea407f39afb2f5007e006e77babc8129d24275c8ce9b5bcc65c945.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _Z15__PopStackFrameP12ThrowContextP13ExceptionInfo()
{

rt_0200f1a0:
    stmdb sp!, {r4, lr}
rt_0200f1a4:
    ldrb r1, [r0, #0x6a]
rt_0200f1a8:
    ldr r12, [r0, #0x60]
rt_0200f1ac:
    mov r4, #0xf
rt_0200f1b0:
    cmp r1, #0
rt_0200f1b4:
    ldr r1, [r0, #0x18]
rt_0200f1b8:
    movne r2, #0x10
rt_0200f1bc:
    moveq r2, #0
rt_0200f1c0:
    add r1, r1, r12
rt_0200f1c4:
    sub lr, r1, r2
rt_0200f1c8:
    mov r3, #1
rt_0200f1cc:
    ldrh r1, [r0, #0x68]
rt_0200f1d0:
    tst r1, r3, lsl r4
rt_0200f1d4:
    ldrne r2, [lr, #-4]!
rt_0200f1d8:
    addne r1, r0, r4, lsl #2
rt_0200f1dc:
    strne r2, [r1, #0x1c]
rt_0200f1e0:
    subs r4, r4, #1
rt_0200f1e4:
    bpl rt_0200f1cc
rt_0200f1e8:
    ldr r1, [r0, #0x18]
rt_0200f1ec:
    add r1, r1, r12
rt_0200f1f0:
    str r1, [r0, #0x14]
rt_0200f1f4:
    ldr r0, [r0, #0x54]
rt_0200f1f8:
    ldmia sp!, {r4, pc}
}
