// Compiler runtime support: _d_feq, _deq.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200BE50, 140 bytes.
// Original bytes SHA256: d647e60f306d2f4623a7c6c0a1968c53d58225e92554b162c7370f39f90b6f76.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _deq()
{

rt_0200be50:
    mov r12, #0x200000
rt_0200be54:
    cmn r12, r1, lsl #1
rt_0200be58:
    bhs rt_0200beb8
rt_0200be5c:
    cmn r12, r3, lsl #1
rt_0200be60:
    bhs rt_0200becc
rt_0200be64:
    orrs r12, r3, r1
rt_0200be68:
    bmi rt_0200be94
rt_0200be6c:
    cmp r1, r3
rt_0200be70:
    cmpeq r0, r2
rt_0200be74:
    moveq r0, #1
rt_0200be78:
    movne r0, #0
rt_0200be7c:
    bx lr
rt_0200be80:
    mov r0, #0
rt_0200be84:
    mrs r12, cpsr
rt_0200be88:
    bic r12, r12, #0x40000000
rt_0200be8c:
    msr cpsr_f, r12
rt_0200be90:
    bx lr
rt_0200be94:
    orr r12, r0, r12, lsl #1
rt_0200be98:
    orrs r12, r12, r2
rt_0200be9c:
    moveq r0, #1
rt_0200bea0:
    bxeq lr
rt_0200bea4:
    cmp r3, r1
rt_0200bea8:
    cmpeq r2, r0
rt_0200beac:
    moveq r0, #1
rt_0200beb0:
    movne r0, #0
rt_0200beb4:
    bx lr
rt_0200beb8:
    bne rt_0200be80
rt_0200bebc:
    cmp r0, #0
rt_0200bec0:
    bhi rt_0200be80
rt_0200bec4:
    cmn r12, r3, lsl #1
rt_0200bec8:
    blo rt_0200be64
rt_0200becc:
    bne rt_0200be80
rt_0200bed0:
    cmp r2, #0
rt_0200bed4:
    bhi rt_0200be80
rt_0200bed8:
    b rt_0200be64
}
