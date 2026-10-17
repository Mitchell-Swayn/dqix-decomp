// Compiler runtime support: _d_add, _dadd.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_add.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_add.s.
// DQIX USA arm9/main: 0x0200AB28, 792 bytes.
// Original bytes SHA256: 2bf0330f455c85b2c0d20e44b4d2cbcaf38dcc7e2f6d3b3c431cdd0a79d3115b.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
// Shared tails have no original relocation. The inline assembler accepts only
// bare branch labels, so encode their ARM branch displacement symbolically.
#define RUNTIME_BRANCH(condition, displacement) (((condition) << 28) | 0x0a000000u | (((((displacement) - 8) / 4)) & 0x00ffffffu))
extern "C" asm void _dadd()
{

rt_0200ab28:
    stmdb sp!, {r4, lr}
rt_0200ab2c:
    eors r12, r1, r3
rt_0200ab30:
    eormi r3, r3, #0x80000000
rt_0200ab34:
    dcd RUNTIME_BRANCH(4, 2788) // Shared runtime tail target: _dsub + 16
rt_0200ab38:
    subs r12, r0, r2
rt_0200ab3c:
    sbcs lr, r1, r3
rt_0200ab40:
    bhs rt_0200ab54
rt_0200ab44:
    adds r2, r2, r12
rt_0200ab48:
    adc r3, r3, lr
rt_0200ab4c:
    subs r0, r0, r12
rt_0200ab50:
    sbc r1, r1, lr
rt_0200ab54:
    mov lr, #0x80000000
rt_0200ab58:
    mov r12, r1, lsr #0x14
rt_0200ab5c:
    orr r1, lr, r1, lsl #11
rt_0200ab60:
    orr r1, r1, r0, lsr #21
rt_0200ab64:
    mov r0, r0, lsl #0xb
rt_0200ab68:
    movs r4, r12, lsl #0x15
rt_0200ab6c:
    cmnne r4, #0x200000
rt_0200ab70:
    beq rt_0200ac50
rt_0200ab74:
    mov r4, r3, lsr #0x14
rt_0200ab78:
    orr r3, lr, r3, lsl #11
rt_0200ab7c:
    orr r3, r3, r2, lsr #21
rt_0200ab80:
    mov r2, r2, lsl #0xb
rt_0200ab84:
    movs lr, r4, lsl #0x15
rt_0200ab88:
    beq rt_0200ac98
rt_0200ab8c:
    subs r4, r12, r4
rt_0200ab90:
    beq rt_0200abe4
rt_0200ab94:
    cmp r4, #0x20
rt_0200ab98:
    ble rt_0200abc8
rt_0200ab9c:
    cmp r4, #0x38
rt_0200aba0:
    movge r4, #0x3f
rt_0200aba4:
    sub r4, r4, #0x20
rt_0200aba8:
    rsb lr, r4, #0x20
rt_0200abac:
    orrs lr, r2, r3, lsl lr
rt_0200abb0:
    mov r2, r3, lsr r4
rt_0200abb4:
    orrne r2, r2, #1
rt_0200abb8:
    adds r0, r0, r2
rt_0200abbc:
    adcs r1, r1, #0
rt_0200abc0:
    blo rt_0200ac0c
rt_0200abc4:
    b rt_0200abf0
rt_0200abc8:
    rsb lr, r4, #0x20
rt_0200abcc:
    movs lr, r2, lsl lr
rt_0200abd0:
    rsb lr, r4, #0x20
rt_0200abd4:
    mov r2, r2, lsr r4
rt_0200abd8:
    orr r2, r2, r3, lsl lr
rt_0200abdc:
    mov r3, r3, lsr r4
rt_0200abe0:
    orrne r2, r2, #1
rt_0200abe4:
    adds r0, r0, r2
rt_0200abe8:
    adcs r1, r1, r3
rt_0200abec:
    blo rt_0200ac0c
rt_0200abf0:
    add r12, r12, #1
rt_0200abf4:
    and r4, r0, #1
rt_0200abf8:
    movs r1, r1, rrx
rt_0200abfc:
    orr r0, r4, r0, rrx
rt_0200ac00:
    mov lr, r12, lsl #0x15
rt_0200ac04:
    cmn lr, #0x200000
rt_0200ac08:
    beq rt_0200ae1c
rt_0200ac0c:
    movs r2, r0, lsl #0x15
rt_0200ac10:
    mov r0, r0, lsr #0xb
rt_0200ac14:
    orr r0, r0, r1, lsl #21
rt_0200ac18:
    add r1, r1, r1
rt_0200ac1c:
    mov r1, r1, lsr #0xc
rt_0200ac20:
    orr r1, r1, r12, lsl #20
rt_0200ac24:
    tst r2, #0x80000000
rt_0200ac28:
    ldmeqia sp!, {r4, lr}
rt_0200ac2c:
    bxeq lr
rt_0200ac30:
    movs r2, r2, lsl #1
rt_0200ac34:
    andeqs r2, r0, #1
rt_0200ac38:
    ldmeqia sp!, {r4, lr}
rt_0200ac3c:
    bxeq lr
rt_0200ac40:
    adds r0, r0, #1
rt_0200ac44:
    adc r1, r1, #0
rt_0200ac48:
    ldmia sp!, {r4, lr}
rt_0200ac4c:
    bx lr
rt_0200ac50:
    cmp r12, #0x800
rt_0200ac54:
    movge lr, #0x80000000
rt_0200ac58:
    movlt lr, #0
rt_0200ac5c:
    bics r12, r12, #0x800
rt_0200ac60:
    beq rt_0200acbc
rt_0200ac64:
    orrs r4, r0, r1, lsl #1
rt_0200ac68:
    bne rt_0200adf8
rt_0200ac6c:
    mov r4, r3, lsr #0x14
rt_0200ac70:
    mov r3, r3, lsl #0xb
rt_0200ac74:
    orr r3, r3, r2, lsr #21
rt_0200ac78:
    mov r2, r2, lsl #0xb
rt_0200ac7c:
    movs r4, r4, lsl #0x15
rt_0200ac80:
    beq rt_0200ade4
rt_0200ac84:
    cmn r4, #0x200000
rt_0200ac88:
    bne rt_0200ade4
rt_0200ac8c:
    orrs r4, r2, r3, lsl #1
rt_0200ac90:
    beq rt_0200ade4
rt_0200ac94:
    b rt_0200adf8
rt_0200ac98:
    cmp r4, #0x800
rt_0200ac9c:
    movge lr, #0x80000000
rt_0200aca0:
    movlt lr, #0
rt_0200aca4:
    bic r12, r12, #0x800
rt_0200aca8:
    bics r4, r4, #0x800
rt_0200acac:
    beq rt_0200ad28
rt_0200acb0:
    orrs r4, r2, r3, lsl #1
rt_0200acb4:
    bne rt_0200adf8
rt_0200acb8:
    b rt_0200ade4
rt_0200acbc:
    orrs r4, r0, r1, lsl #1
rt_0200acc0:
    beq rt_0200acfc
rt_0200acc4:
    mov r12, #1
rt_0200acc8:
    bic r1, r1, #0x80000000
rt_0200accc:
    mov r4, r3, lsr #0x14
rt_0200acd0:
    mov r3, r3, lsl #0xb
rt_0200acd4:
    orr r3, r3, r2, lsr #21
rt_0200acd8:
    mov r2, r2, lsl #0xb
rt_0200acdc:
    movs r4, r4, lsl #0x15
rt_0200ace0:
    cmnne r4, #0x200000
rt_0200ace4:
    mov r4, r4, lsr #0x15
rt_0200ace8:
    orr r4, r4, lr, lsr #20
rt_0200acec:
    beq rt_0200ac98
rt_0200acf0:
    orr r3, r3, #0x80000000
rt_0200acf4:
    orr r12, r12, lr, lsr #20
rt_0200acf8:
    b rt_0200ab8c
rt_0200acfc:
    mov r12, r3, lsr #0x14
rt_0200ad00:
    mov r1, r3, lsl #0xb
rt_0200ad04:
    orr r1, r1, r2, lsr #21
rt_0200ad08:
    mov r0, r2, lsl #0xb
rt_0200ad0c:
    movs r4, r12, lsl #0x15
rt_0200ad10:
    beq rt_0200adb0
rt_0200ad14:
    cmn r4, #0x200000
rt_0200ad18:
    bne rt_0200adb0
rt_0200ad1c:
    orrs r4, r0, r1, lsl #1
rt_0200ad20:
    beq rt_0200ade4
rt_0200ad24:
    b rt_0200adfc
rt_0200ad28:
    orrs r4, r2, r3, lsl #1
rt_0200ad2c:
    beq rt_0200adc0
rt_0200ad30:
    mov r4, #1
rt_0200ad34:
    bic r3, r3, #0x80000000
rt_0200ad38:
    cmp r1, #0
rt_0200ad3c:
    bpl rt_0200ad4c
rt_0200ad40:
    orr r12, r12, lr, lsr #20
rt_0200ad44:
    orr r4, r4, lr, lsr #20
rt_0200ad48:
    b rt_0200ab8c
rt_0200ad4c:
    adds r0, r0, r2
rt_0200ad50:
    adcs r1, r1, r3
rt_0200ad54:
    blo rt_0200ad6c
rt_0200ad58:
    add r12, r12, #1
rt_0200ad5c:
    and r4, r0, #1
rt_0200ad60:
    movs r1, r1, rrx
rt_0200ad64:
    mov r0, r0, rrx
rt_0200ad68:
    orr r0, r0, r4
rt_0200ad6c:
    cmp r1, #0
rt_0200ad70:
    subges r12, r12, #1
rt_0200ad74:
    movs r2, r0, lsl #0x15
rt_0200ad78:
    mov r0, r0, lsr #0xb
rt_0200ad7c:
    orr r0, r0, r1, lsl #21
rt_0200ad80:
    add r1, r1, r1
rt_0200ad84:
    orr r1, lr, r1, lsr #12
rt_0200ad88:
    orr r1, r1, r12, lsl #20
rt_0200ad8c:
    ldmeqia sp!, {r4, lr}
rt_0200ad90:
    bxeq lr
rt_0200ad94:
    tst r2, #0x80000000
rt_0200ad98:
    ldmeqia sp!, {r4, lr}
rt_0200ad9c:
    bxeq lr
rt_0200ada0:
    movs r2, r2, lsl #1
rt_0200ada4:
    andeqs r2, r0, #1
rt_0200ada8:
    ldmeqia sp!, {r4, lr}
rt_0200adac:
    bxeq lr
rt_0200adb0:
    mov r1, r3
rt_0200adb4:
    mov r0, r2
rt_0200adb8:
    ldmia sp!, {r4, lr}
rt_0200adbc:
    bx lr
rt_0200adc0:
    cmp r1, #0
rt_0200adc4:
    subges r12, r12, #1
rt_0200adc8:
    mov r0, r0, lsr #0xb
rt_0200adcc:
    orr r0, r0, r1, lsl #21
rt_0200add0:
    add r1, r1, r1
rt_0200add4:
    orr r1, lr, r1, lsr #12
rt_0200add8:
    orr r1, r1, r12, lsl #20
rt_0200addc:
    ldmia sp!, {r4, lr}
rt_0200ade0:
    bx lr
rt_0200ade4:
    ldr r1, [pc, #80] // Literal at 0x0200ae3c
rt_0200ade8:
    orr r1, lr, r1
rt_0200adec:
    mov r0, #0
rt_0200adf0:
    ldmia sp!, {r4, lr}
rt_0200adf4:
    bx lr
rt_0200adf8:
    mov r1, r3
rt_0200adfc:
    mvn r0, #0
rt_0200ae00:
    bic r1, r0, #0x80000000
rt_0200ae04:
    ldmia sp!, {r4, lr}
rt_0200ae08:
    bx lr
rt_0200ae0c:
    mvn r0, #0
rt_0200ae10:
    bic r1, r0, #0x80000000
rt_0200ae14:
    ldmia sp!, {r4, lr}
rt_0200ae18:
    bx lr
rt_0200ae1c:
    cmp r12, #0x800
rt_0200ae20:
    movge lr, #0x80000000
rt_0200ae24:
    movlt lr, #0
rt_0200ae28:
    ldr r1, [pc, #12] // Literal at 0x0200ae3c
rt_0200ae2c:
    orr r1, lr, r1
rt_0200ae30:
    mov r0, #0
rt_0200ae34:
    ldmia sp!, {r4, lr}
rt_0200ae38:
    bx lr
rt_0200ae3c:
    dcd 0x7ff00000 // Literal/table data, not an instruction.
}
