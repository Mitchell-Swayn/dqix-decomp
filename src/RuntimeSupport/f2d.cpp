// Compiler runtime support: _f_ftod, _f2d.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_ftod.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_ftod.s.
// DQIX USA arm9/main: 0x0200C578, 132 bytes.
// Original bytes SHA256: 29e8c250fe28c58be66a491d6465ae3c794af8831906ec999a9e1ed1450d766c.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _f2d()
{

rt_0200c578:
    and r2, r0, #0x80000000
rt_0200c57c:
    mov r12, r0, lsr #0x17
rt_0200c580:
    mov r3, r0, lsl #9
rt_0200c584:
    ands r12, r12, #0xff
rt_0200c588:
    beq rt_0200c5a8
rt_0200c58c:
    cmp r12, #0xff
rt_0200c590:
    beq rt_0200c5d4
rt_0200c594:
    add r12, r12, #0x380
rt_0200c598:
    mov r0, r3, lsl #0x14
rt_0200c59c:
    orr r1, r2, r3, lsr #12
rt_0200c5a0:
    orr r1, r1, r12, lsl #20
rt_0200c5a4:
    bx lr
rt_0200c5a8:
    cmp r3, #0
rt_0200c5ac:
    bne rt_0200c5bc
rt_0200c5b0:
    mov r1, r2
rt_0200c5b4:
    mov r0, #0
rt_0200c5b8:
    bx lr
rt_0200c5bc:
    mov r3, r3, lsr #1
rt_0200c5c0:
    clz r12, r3
rt_0200c5c4:
    movs r3, r3, lsl r12
rt_0200c5c8:
    rsb r12, r12, #1
rt_0200c5cc:
    add r3, r3, r3
rt_0200c5d0:
    b rt_0200c594
rt_0200c5d4:
    cmp r3, #0
rt_0200c5d8:
    bhi rt_0200c5ec
rt_0200c5dc:
    ldr r1, [pc, #20] // Literal at 0x0200c5f8
rt_0200c5e0:
    orr r1, r1, r2
rt_0200c5e4:
    mov r0, #0
rt_0200c5e8:
    bx lr
rt_0200c5ec:
    mvn r0, #0
rt_0200c5f0:
    bic r1, r0, #0x80000000
rt_0200c5f4:
    bx lr
rt_0200c5f8:
    dcd 0x7ff00000 // Literal/table data, not an instruction.
}
