// Compiler runtime support: _f_sub, _fsub.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_sub.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_sub.s.
// DQIX USA arm9/main: 0x0200CAA4, 632 bytes.
// Original bytes SHA256: 2e3a275496dab40c1cc3adab85bf88ace3cfebb4aab2c7b65a24a6b099f68e29.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
// Shared tails have no original relocation. The inline assembler accepts only
// bare branch labels, so encode their ARM branch displacement symbolically.
#define RUNTIME_BRANCH(condition, displacement) (((condition) << 28) | 0x0a000000u | (((((displacement) - 8) / 4)) & 0x00ffffffu))
extern "C" asm void _fsub()
{

rt_0200caa4:
    eors r2, r0, r1
rt_0200caa8:
    eormi r1, r1, #0x80000000
rt_0200caac:
    dcd RUNTIME_BRANCH(4, -4324) // Shared runtime tail target: _fadd + 12
rt_0200cab0:
    subs r12, r0, r1
rt_0200cab4:
    eorlo r12, r12, #0x80000000
rt_0200cab8:
    sublo r0, r0, r12
rt_0200cabc:
    addlo r1, r1, r12
rt_0200cac0:
    mov r2, #0x80000000
rt_0200cac4:
    mov r3, r0, lsr #0x17
rt_0200cac8:
    orr r0, r2, r0, lsl #8
rt_0200cacc:
    ands r12, r3, #0xff
rt_0200cad0:
    cmpne r12, #0xff
rt_0200cad4:
    beq rt_0200cbcc
rt_0200cad8:
    mov r12, r1, lsr #0x17
rt_0200cadc:
    orr r1, r2, r1, lsl #8
rt_0200cae0:
    ands r2, r12, #0xff
rt_0200cae4:
    beq rt_0200cc0c
rt_0200cae8:
    subs r12, r3, r12
rt_0200caec:
    beq rt_0200cb30
rt_0200caf0:
    rsb r2, r12, #0x20
rt_0200caf4:
    movs r2, r1, lsl r2
rt_0200caf8:
    mov r1, r1, lsr r12
rt_0200cafc:
    orrne r1, r1, #1
rt_0200cb00:
    subs r0, r0, r1
rt_0200cb04:
    bpl rt_0200cb74
rt_0200cb08:
    ands r1, r0, #0xff
rt_0200cb0c:
    add r0, r0, r0
rt_0200cb10:
    mov r0, r0, lsr #9
rt_0200cb14:
    orr r0, r0, r3, lsl #23
rt_0200cb18:
    tst r1, #0x80
rt_0200cb1c:
    bxeq lr
rt_0200cb20:
    ands r1, r1, #0x7f
rt_0200cb24:
    andeqs r1, r0, #1
rt_0200cb28:
    addne r0, r0, #1
rt_0200cb2c:
    bx lr
rt_0200cb30:
    subs r0, r0, r1
rt_0200cb34:
    beq rt_0200ccd8
rt_0200cb38:
    mov r2, r3, lsl #0x17
rt_0200cb3c:
    and r2, r2, #0x80000000
rt_0200cb40:
    bic r3, r3, #0x100
rt_0200cb44:
    clz r12, r0
rt_0200cb48:
    movs r0, r0, lsl r12
rt_0200cb4c:
    sub r3, r3, r12
rt_0200cb50:
    cmp r3, #0
rt_0200cb54:
    bgt rt_0200cb64
rt_0200cb58:
    rsb r3, r3, #9
rt_0200cb5c:
    orr r0, r2, r0, lsr r3
rt_0200cb60:
    bx lr
rt_0200cb64:
    add r0, r0, r0
rt_0200cb68:
    orr r0, r2, r0, lsr #9
rt_0200cb6c:
    orr r0, r0, r3, lsl #23
rt_0200cb70:
    bx lr
rt_0200cb74:
    mov r2, r3, lsl #0x17
rt_0200cb78:
    and r2, r2, #0x80000000
rt_0200cb7c:
    bic r3, r3, #0x100
rt_0200cb80:
    clz r12, r0
rt_0200cb84:
    movs r0, r0, lsl r12
rt_0200cb88:
    sub r3, r3, r12
rt_0200cb8c:
    cmp r3, #0
rt_0200cb90:
    bgt rt_0200cba0
rt_0200cb94:
    rsb r3, r3, #9
rt_0200cb98:
    orr r0, r2, r0, lsr r3
rt_0200cb9c:
    bx lr
rt_0200cba0:
    ands r1, r0, #0xff
rt_0200cba4:
    add r0, r0, r0
rt_0200cba8:
    orr r0, r2, r0, lsr #9
rt_0200cbac:
    orr r0, r0, r3, lsl #23
rt_0200cbb0:
    bxeq lr
rt_0200cbb4:
    tst r1, #0x80
rt_0200cbb8:
    bxeq lr
rt_0200cbbc:
    ands r1, r1, #0x7f
rt_0200cbc0:
    andeqs r1, r0, #1
rt_0200cbc4:
    addne r0, r0, #1
rt_0200cbc8:
    bx lr
rt_0200cbcc:
    cmp r3, #0x100
rt_0200cbd0:
    movge r2, #0x80000000
rt_0200cbd4:
    movlt r2, #0
rt_0200cbd8:
    ands r3, r3, #0xff
rt_0200cbdc:
    beq rt_0200cc34
rt_0200cbe0:
    movs r0, r0, lsl #1
rt_0200cbe4:
    bne rt_0200cd0c
rt_0200cbe8:
    mov r12, r1, lsr #0x17
rt_0200cbec:
    mov r1, r1, lsl #9
rt_0200cbf0:
    ands r12, r12, #0xff
rt_0200cbf4:
    beq rt_0200cd00
rt_0200cbf8:
    cmp r12, #0xff
rt_0200cbfc:
    blt rt_0200cd00
rt_0200cc00:
    cmp r1, #0
rt_0200cc04:
    beq rt_0200cd14
rt_0200cc08:
    b rt_0200cd0c
rt_0200cc0c:
    cmp r12, #0x100
rt_0200cc10:
    movge r2, #0x80000000
rt_0200cc14:
    movlt r2, #0
rt_0200cc18:
    and r3, r3, #0xff
rt_0200cc1c:
    ands r12, r12, #0xff
rt_0200cc20:
    beq rt_0200cc9c
rt_0200cc24:
    eor r2, r2, #0x80000000
rt_0200cc28:
    movs r1, r1, lsl #1
rt_0200cc2c:
    bne rt_0200cd0c
rt_0200cc30:
    b rt_0200cd00
rt_0200cc34:
    movs r0, r0, lsl #1
rt_0200cc38:
    beq rt_0200cc6c
rt_0200cc3c:
    mov r0, r0, lsr #1
rt_0200cc40:
    mov r3, #1
rt_0200cc44:
    mov r12, r1, lsr #0x17
rt_0200cc48:
    mov r1, r1, lsl #8
rt_0200cc4c:
    ands r12, r12, #0xff
rt_0200cc50:
    beq rt_0200cc9c
rt_0200cc54:
    cmp r12, #0xff
rt_0200cc58:
    beq rt_0200cc24
rt_0200cc5c:
    orr r1, r1, #0x80000000
rt_0200cc60:
    orr r3, r3, r2, lsr #23
rt_0200cc64:
    orr r12, r12, r2, lsr #23
rt_0200cc68:
    b rt_0200cae8
rt_0200cc6c:
    mov r3, r1, lsr #0x17
rt_0200cc70:
    mov r0, r1, lsl #9
rt_0200cc74:
    ands r2, r3, #0xff
rt_0200cc78:
    beq rt_0200cc90
rt_0200cc7c:
    cmp r2, #0xff
rt_0200cc80:
    blt rt_0200ccb8
rt_0200cc84:
    cmp r0, #0
rt_0200cc88:
    bne rt_0200ccf8
rt_0200cc8c:
    b rt_0200cd00
rt_0200cc90:
    cmp r0, #0
rt_0200cc94:
    beq rt_0200ccd8
rt_0200cc98:
    b rt_0200ccb8
rt_0200cc9c:
    movs r1, r1, lsl #1
rt_0200cca0:
    beq rt_0200ccc0
rt_0200cca4:
    mov r1, r1, lsr #1
rt_0200cca8:
    mov r12, #1
rt_0200ccac:
    orr r12, r12, r2, lsr #23
rt_0200ccb0:
    orr r3, r3, r2, lsr #23
rt_0200ccb4:
    b rt_0200cae8
rt_0200ccb8:
    mov r0, r1
rt_0200ccbc:
    bx lr
rt_0200ccc0:
    cmp r0, #0
rt_0200ccc4:
    subges r3, r3, #1
rt_0200ccc8:
    add r0, r0, r0
rt_0200cccc:
    orr r0, r2, r0, lsr #9
rt_0200ccd0:
    orr r0, r0, r3, lsl #23
rt_0200ccd4:
    bx lr
rt_0200ccd8:
    mov r0, #0
rt_0200ccdc:
    bx lr
rt_0200cce0:
    cmp r0, #0
rt_0200cce4:
    subges r3, r3, #1
rt_0200cce8:
    add r0, r0, r0
rt_0200ccec:
    mov r0, r0, lsr #9
rt_0200ccf0:
    orr r0, r0, r3, lsl #23
rt_0200ccf4:
    bx lr
rt_0200ccf8:
    mvn r0, #0x80000000
rt_0200ccfc:
    bx lr
rt_0200cd00:
    mov r0, #0xff000000
rt_0200cd04:
    orr r0, r2, r0, lsr #1
rt_0200cd08:
    bx lr
rt_0200cd0c:
    mvn r0, #0x80000000
rt_0200cd10:
    bx lr
rt_0200cd14:
    mvn r0, #0x80000000
rt_0200cd18:
    bx lr
}
