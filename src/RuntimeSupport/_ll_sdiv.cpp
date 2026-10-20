// Compiler runtime support: _ll_div, _ll_sdiv.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _ll_div.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_ll_div.s.
// DQIX USA arm9/main: 0x0200CD2C, 432 bytes.
// Original bytes SHA256: d3074a755593af60455da034ffaa8829a18a4a6e3872817c1f2fcb7cc250bfc2.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" void _s32_div_f();
extern "C" asm void _ll_sdiv()
{

rt_0200cd2c:
    stmdb sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200cd30:
    eor r4, r1, r3
rt_0200cd34:
    mov r4, r4, asr #1
rt_0200cd38:
    mov r4, r4, lsl #1
rt_0200cd3c:
    orrs r5, r3, r2
rt_0200cd40:
    bne rt_0200cd4c
rt_0200cd44:
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200cd48:
    bx lr
rt_0200cd4c:
    mov r5, r0, lsr #0x1f
rt_0200cd50:
    add r5, r5, r1
rt_0200cd54:
    mov r6, r2, lsr #0x1f
rt_0200cd58:
    add r6, r6, r3
rt_0200cd5c:
    orrs r6, r5, r6
rt_0200cd60:
    bne rt_0200cd80
rt_0200cd64:
    mov r1, r2
rt_0200cd68:
    bl _s32_div_f
rt_0200cd6c:
    ands r4, r4, #1
rt_0200cd70:
    movne r0, r1
rt_0200cd74:
    mov r1, r0, asr #0x1f
rt_0200cd78:
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200cd7c:
    bx lr
rt_0200cd80:
    cmp r1, #0
rt_0200cd84:
    bge rt_0200cd90
rt_0200cd88:
    rsbs r0, r0, #0
rt_0200cd8c:
    rsc r1, r1, #0
rt_0200cd90:
    cmp r3, #0
rt_0200cd94:
    bge rt_0200cda0
rt_0200cd98:
    rsbs r2, r2, #0
rt_0200cd9c:
    rsc r3, r3, #0
rt_0200cda0:
    orrs r5, r1, r0
rt_0200cda4:
    beq rt_0200cec4
rt_0200cda8:
    mov r5, #0
rt_0200cdac:
    mov r6, #1
rt_0200cdb0:
    cmp r3, #0
rt_0200cdb4:
    bmi rt_0200cdcc
rt_0200cdb8:
    add r5, r5, #1
rt_0200cdbc:
    adds r2, r2, r2
rt_0200cdc0:
    adcs r3, r3, r3
rt_0200cdc4:
    bpl rt_0200cdb8
rt_0200cdc8:
    add r6, r6, r5
rt_0200cdcc:
    cmp r1, #0
rt_0200cdd0:
    blt rt_0200cdec
rt_0200cdd4:
    cmp r6, #1
rt_0200cdd8:
    beq rt_0200cdec
rt_0200cddc:
    sub r6, r6, #1
rt_0200cde0:
    adds r0, r0, r0
rt_0200cde4:
    adcs r1, r1, r1
rt_0200cde8:
    bpl rt_0200cdd4
rt_0200cdec:
    mov r7, #0
rt_0200cdf0:
    mov r12, #0
rt_0200cdf4:
    mov r11, #0
rt_0200cdf8:
    b rt_0200ce14
rt_0200cdfc:
    orr r12, r12, #1
rt_0200ce00:
    subs r6, r6, #1
rt_0200ce04:
    beq rt_0200ce6c
rt_0200ce08:
    adds r0, r0, r0
rt_0200ce0c:
    adcs r1, r1, r1
rt_0200ce10:
    adcs r7, r7, r7
rt_0200ce14:
    subs r0, r0, r2
rt_0200ce18:
    sbcs r1, r1, r3
rt_0200ce1c:
    sbcs r7, r7, #0
rt_0200ce20:
    adds r12, r12, r12
rt_0200ce24:
    adc r11, r11, r11
rt_0200ce28:
    cmp r7, #0
rt_0200ce2c:
    bge rt_0200cdfc
rt_0200ce30:
    subs r6, r6, #1
rt_0200ce34:
    beq rt_0200ce64
rt_0200ce38:
    adds r0, r0, r0
rt_0200ce3c:
    adcs r1, r1, r1
rt_0200ce40:
    adc r7, r7, r7
rt_0200ce44:
    adds r0, r0, r2
rt_0200ce48:
    adcs r1, r1, r3
rt_0200ce4c:
    adc r7, r7, #0
rt_0200ce50:
    adds r12, r12, r12
rt_0200ce54:
    adc r11, r11, r11
rt_0200ce58:
    cmp r7, #0
rt_0200ce5c:
    bge rt_0200cdfc
rt_0200ce60:
    b rt_0200ce30
rt_0200ce64:
    adds r0, r0, r2
rt_0200ce68:
    adc r1, r1, r3
rt_0200ce6c:
    ands r7, r4, #1
rt_0200ce70:
    moveq r0, r12
rt_0200ce74:
    moveq r1, r11
rt_0200ce78:
    beq rt_0200cea4
rt_0200ce7c:
    subs r7, r5, #0x20
rt_0200ce80:
    movge r0, r1, lsr r7
rt_0200ce84:
    bge rt_0200cec8
rt_0200ce88:
    rsb r7, r5, #0x20
rt_0200ce8c:
    mov r0, r0, lsr r5
rt_0200ce90:
    orr r0, r0, r1, lsl r7
rt_0200ce94:
    mov r1, r1, lsr r5
rt_0200ce98:
    b rt_0200cea4
rt_0200ce9c:
    mov r0, r1, lsr r7
rt_0200cea0:
    mov r1, #0
rt_0200cea4:
    cmp r4, #0
rt_0200cea8:
    blt rt_0200ceb4
rt_0200ceac:
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200ceb0:
    bx lr
rt_0200ceb4:
    rsbs r0, r0, #0
rt_0200ceb8:
    rsc r1, r1, #0
rt_0200cebc:
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200cec0:
    bx lr
rt_0200cec4:
    mov r0, #0
rt_0200cec8:
    mov r1, #0
rt_0200cecc:
    cmp r4, #0
rt_0200ced0:
    blt rt_0200ceb4
rt_0200ced4:
    ldmia sp!, {r4, r5, r6, r7, r11, r12, lr}
rt_0200ced8:
    bx lr
}
