// Compiler runtime support: _d_dtoull, _ll_ufrom_d.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_dtoull.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_dtoull.s.
// DQIX USA arm9/main: 0x0200AFE8, 140 bytes.
// Original bytes SHA256: 69a48b26acc1871c63b88f7920dc071f4111e0b99aae88821b76a956890bae8a.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _ll_ufrom_d()
{

rt_0200afe8:
    tst r1, #0x80000000
rt_0200afec:
    bne rt_0200b04c
rt_0200aff0:
    ldr r2, [pc, #120] // Literal at 0x0200b070
rt_0200aff4:
    subs r2, r2, r1, lsr #20
rt_0200aff8:
    blt rt_0200b064
rt_0200affc:
    cmp r2, #0x40
rt_0200b000:
    bge rt_0200b040
rt_0200b004:
    mov r12, r1, lsl #0xb
rt_0200b008:
    orr r12, r12, #0x80000000
rt_0200b00c:
    orr r12, r12, r0, lsr #21
rt_0200b010:
    cmp r2, #0x20
rt_0200b014:
    ble rt_0200b028
rt_0200b018:
    sub r2, r2, #0x20
rt_0200b01c:
    mov r1, #0
rt_0200b020:
    mov r0, r12, lsr r2
rt_0200b024:
    bx lr
rt_0200b028:
    mov r3, r0, lsl #0xb
rt_0200b02c:
    mov r1, r12, lsr r2
rt_0200b030:
    mov r0, r3, lsr r2
rt_0200b034:
    rsb r2, r2, #0x20
rt_0200b038:
    orr r0, r0, r12, lsl r2
rt_0200b03c:
    bx lr
rt_0200b040:
    mov r1, #0
rt_0200b044:
    mov r0, #0
rt_0200b048:
    bx lr
rt_0200b04c:
    cmn r1, #0x100000
rt_0200b050:
    cmpeq r0, #0
rt_0200b054:
    bhi rt_0200b064
rt_0200b058:
    mov r1, #0
rt_0200b05c:
    mov r0, #0
rt_0200b060:
    bx lr
rt_0200b064:
    mvn r1, #0
rt_0200b068:
    mvn r0, #0
rt_0200b06c:
    bx lr
rt_0200b070:
    dcd 0x0000043e // Literal/table data, not an instruction.
}
