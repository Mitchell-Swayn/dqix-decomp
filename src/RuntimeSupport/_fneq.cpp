// Compiler runtime support: _f_fne, _fneq.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_cmp.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_cmp.s.
// DQIX USA arm9/main: 0x0200C14C, 104 bytes.
// Original bytes SHA256: 9cd872ef581cc397b29e335f1e842bee746d9c93434499fafb6527bea0071a5d.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _fneq()
{

rt_0200c14c:
    mov r3, #0xff000000
rt_0200c150:
    cmp r3, r0, lsl #1
rt_0200c154:
    blo rt_0200c1a0
rt_0200c158:
    cmp r3, r1, lsl #1
rt_0200c15c:
    blo rt_0200c1a0
rt_0200c160:
    orr r3, r0, r1
rt_0200c164:
    movs r3, r3, lsl #1
rt_0200c168:
    moveq r0, #0
rt_0200c16c:
    bne rt_0200c180
rt_0200c170:
    mrs r12, cpsr
rt_0200c174:
    orr r12, r12, #0x40000000
rt_0200c178:
    msr cpsr_f, r12
rt_0200c17c:
    bx lr
rt_0200c180:
    cmp r0, r1
rt_0200c184:
    movne r0, #1
rt_0200c188:
    moveq r0, #0
rt_0200c18c:
    mrs r12, cpsr
rt_0200c190:
    bicne r12, r12, #0x40000000
rt_0200c194:
    orreq r12, r12, #0x40000000
rt_0200c198:
    msr cpsr_f, r12
rt_0200c19c:
    bx lr
rt_0200c1a0:
    mov r0, #1
rt_0200c1a4:
    mrs r12, cpsr
rt_0200c1a8:
    bic r12, r12, #0x40000000
rt_0200c1ac:
    msr cpsr_f, r12
rt_0200c1b0:
    bx lr

// Shared compiler runtime tail following the named function.
    eor r0, r0, r1
    eor r1, r0, r1
    eor r0, r0, r1
}
