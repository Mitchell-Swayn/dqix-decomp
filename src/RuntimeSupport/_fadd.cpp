// Compiler runtime support: _f_add, _fadd.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_add.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_add.s.
// DQIX USA arm9/main: 0x0200B9BC, 540 bytes.
// Original bytes SHA256: 8d35dff4865482d187190fc373ad3e0e002ee516689851df0a691d2d36b1f7a3.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
// Shared tails have no original relocation. The inline assembler accepts only
// bare branch labels, so encode their ARM branch displacement symbolically.
#define RUNTIME_BRANCH(condition, displacement) (((condition) << 28) | 0x0a000000u | (((((displacement) - 8) / 4)) & 0x00ffffffu))
extern "C" asm void _fadd()
{

rt_0200b9bc:
    eors r2, r0, r1
rt_0200b9c0:
    eormi r1, r1, #0x80000000
rt_0200b9c4:
    dcd RUNTIME_BRANCH(4, 4332) // Shared runtime tail target: _fsub + 12
rt_0200b9c8:
    subs r12, r0, r1
rt_0200b9cc:
    sublo r0, r0, r12
rt_0200b9d0:
    addlo r1, r1, r12
rt_0200b9d4:
    mov r2, #0x80000000
rt_0200b9d8:
    mov r3, r0, lsr #0x17
rt_0200b9dc:
    orr r0, r2, r0, lsl #8
rt_0200b9e0:
    ands r12, r3, #0xff
rt_0200b9e4:
    cmpne r12, #0xff
rt_0200b9e8:
    beq rt_0200ba5c
rt_0200b9ec:
    mov r12, r1, lsr #0x17
rt_0200b9f0:
    orr r1, r2, r1, lsl #8
rt_0200b9f4:
    ands r2, r12, #0xff
rt_0200b9f8:
    beq rt_0200ba9c
rt_0200b9fc:
    subs r12, r3, r12
rt_0200ba00:
    beq rt_0200ba14
rt_0200ba04:
    rsb r2, r12, #0x20
rt_0200ba08:
    movs r2, r1, lsl r2
rt_0200ba0c:
    mov r1, r1, lsr r12
rt_0200ba10:
    orrne r1, r1, #1
rt_0200ba14:
    adds r0, r0, r1
rt_0200ba18:
    blo rt_0200ba34
rt_0200ba1c:
    and r1, r0, #1
rt_0200ba20:
    orr r0, r1, r0, rrx
rt_0200ba24:
    add r3, r3, #1
rt_0200ba28:
    and r2, r3, #0xff
rt_0200ba2c:
    cmp r2, #0xff
rt_0200ba30:
    beq rt_0200bba4
rt_0200ba34:
    ands r1, r0, #0xff
rt_0200ba38:
    add r0, r0, r0
rt_0200ba3c:
    mov r0, r0, lsr #9
rt_0200ba40:
    orr r0, r0, r3, lsl #23
rt_0200ba44:
    tst r1, #0x80
rt_0200ba48:
    bxeq lr
rt_0200ba4c:
    ands r1, r1, #0x7f
rt_0200ba50:
    andeqs r1, r0, #1
rt_0200ba54:
    addne r0, r0, #1
rt_0200ba58:
    bx lr
rt_0200ba5c:
    cmp r3, #0x100
rt_0200ba60:
    movge r2, #0x80000000
rt_0200ba64:
    movlt r2, #0
rt_0200ba68:
    ands r3, r3, #0xff
rt_0200ba6c:
    beq rt_0200bac0
rt_0200ba70:
    movs r0, r0, lsl #1
rt_0200ba74:
    bne rt_0200bbd0
rt_0200ba78:
    mov r12, r1, lsr #0x17
rt_0200ba7c:
    mov r1, r1, lsl #9
rt_0200ba80:
    ands r12, r12, #0xff
rt_0200ba84:
    beq rt_0200bbc4
rt_0200ba88:
    cmp r12, #0xff
rt_0200ba8c:
    blt rt_0200bbc4
rt_0200ba90:
    cmp r1, #0
rt_0200ba94:
    beq rt_0200bbc4
rt_0200ba98:
    b rt_0200bbd0
rt_0200ba9c:
    cmp r3, #0x100
rt_0200baa0:
    movge r2, #0x80000000
rt_0200baa4:
    movlt r2, #0
rt_0200baa8:
    and r3, r3, #0xff
rt_0200baac:
    ands r12, r12, #0xff
rt_0200bab0:
    beq rt_0200bb1c
rt_0200bab4:
    movs r1, r1, lsl #1
rt_0200bab8:
    bne rt_0200bbd0
rt_0200babc:
    b rt_0200bbc4
rt_0200bac0:
    movs r0, r0, lsl #1
rt_0200bac4:
    beq rt_0200baf8
rt_0200bac8:
    mov r3, #1
rt_0200bacc:
    mov r0, r0, lsr #1
rt_0200bad0:
    mov r12, r1, lsr #0x17
rt_0200bad4:
    mov r1, r1, lsl #8
rt_0200bad8:
    ands r12, r12, #0xff
rt_0200badc:
    beq rt_0200bb1c
rt_0200bae0:
    cmp r12, #0xff
rt_0200bae4:
    beq rt_0200bab4
rt_0200bae8:
    orr r1, r1, #0x80000000
rt_0200baec:
    orr r3, r3, r2, lsr #23
rt_0200baf0:
    orr r12, r12, r2, lsr #23
rt_0200baf4:
    b rt_0200b9fc
rt_0200baf8:
    mov r3, r1, lsr #0x17
rt_0200bafc:
    mov r0, r1, lsl #9
rt_0200bb00:
    ands r3, r3, #0xff
rt_0200bb04:
    beq rt_0200bb84
rt_0200bb08:
    cmp r3, #0xff
rt_0200bb0c:
    blt rt_0200bb84
rt_0200bb10:
    cmp r0, #0
rt_0200bb14:
    beq rt_0200bbc4
rt_0200bb18:
    b rt_0200bbbc
rt_0200bb1c:
    movs r1, r1, lsl #1
rt_0200bb20:
    beq rt_0200bb8c
rt_0200bb24:
    mov r1, r1, lsr #1
rt_0200bb28:
    mov r12, #1
rt_0200bb2c:
    orr r3, r3, r2, lsr #23
rt_0200bb30:
    orr r12, r12, r2, lsr #23
rt_0200bb34:
    cmp r0, #0
rt_0200bb38:
    bmi rt_0200b9fc
rt_0200bb3c:
    adds r0, r0, r1
rt_0200bb40:
    blo rt_0200bb50
rt_0200bb44:
    and r1, r0, #1
rt_0200bb48:
    orr r0, r1, r0, rrx
rt_0200bb4c:
    add r12, r12, #1
rt_0200bb50:
    cmp r0, #0
rt_0200bb54:
    subge r12, r12, #1
rt_0200bb58:
    ands r1, r0, #0xff
rt_0200bb5c:
    add r0, r0, r0
rt_0200bb60:
    mov r0, r0, lsr #9
rt_0200bb64:
    orr r0, r0, r12, lsl #23
rt_0200bb68:
    bxeq lr
rt_0200bb6c:
    tst r1, #0x80
rt_0200bb70:
    bxeq lr
rt_0200bb74:
    ands r1, r1, #0x7f
rt_0200bb78:
    andeqs r1, r0, #1
rt_0200bb7c:
    addne r0, r0, #1
rt_0200bb80:
    bx lr
rt_0200bb84:
    mov r0, r1
rt_0200bb88:
    bx lr
rt_0200bb8c:
    cmp r0, #0
rt_0200bb90:
    subges r3, r3, #1
rt_0200bb94:
    add r0, r0, r0
rt_0200bb98:
    orr r0, r2, r0, lsr #9
rt_0200bb9c:
    orr r0, r0, r3, lsl #23
rt_0200bba0:
    bx lr
rt_0200bba4:
    cmp r3, #0x100
rt_0200bba8:
    movge r2, #0x80000000
rt_0200bbac:
    movlt r2, #0
rt_0200bbb0:
    mov r0, #0xff000000
rt_0200bbb4:
    orr r0, r2, r0, lsr #1
rt_0200bbb8:
    bx lr
rt_0200bbbc:
    mvn r0, #0x80000000
rt_0200bbc0:
    bx lr
rt_0200bbc4:
    mov r0, #0xff000000
rt_0200bbc8:
    orr r0, r2, r0, lsr #1
rt_0200bbcc:
    bx lr
rt_0200bbd0:
    mvn r0, #0x80000000
rt_0200bbd4:
    bx lr
}
