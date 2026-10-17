// Compiler runtime support: _s32_div_f.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _s32_div_f.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_s32_div_f.s.
// DQIX USA arm9/main: 0x0200CF44, 524 bytes.
// Original bytes SHA256: e8183a62ffe6a54210cd7d025b01431ff792025c1b45a0e8537abd8cec16ccfb.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _s32_div_f()
{

rt_0200cf44:
    eor r12, r0, r1
rt_0200cf48:
    and r12, r12, #0x80000000
rt_0200cf4c:
    cmp r0, #0
rt_0200cf50:
    rsblt r0, r0, #0
rt_0200cf54:
    addlt r12, r12, #1
rt_0200cf58:
    cmp r1, #0
rt_0200cf5c:
    rsblt r1, r1, #0
rt_0200cf60:
    beq rt_0200d13c
rt_0200cf64:
    cmp r0, r1
rt_0200cf68:
    movlo r1, r0
rt_0200cf6c:
    movlo r0, #0
rt_0200cf70:
    blo rt_0200d13c
rt_0200cf74:
    mov r2, #0x1c
rt_0200cf78:
    mov r3, r0, lsr #4
rt_0200cf7c:
    cmp r1, r3, lsr #12
rt_0200cf80:
    suble r2, r2, #0x10
rt_0200cf84:
    movle r3, r3, lsr #0x10
rt_0200cf88:
    cmp r1, r3, lsr #4
rt_0200cf8c:
    suble r2, r2, #8
rt_0200cf90:
    movle r3, r3, lsr #8
rt_0200cf94:
    cmp r1, r3
rt_0200cf98:
    suble r2, r2, #4
rt_0200cf9c:
    movle r3, r3, lsr #4
rt_0200cfa0:
    mov r0, r0, lsl r2
rt_0200cfa4:
    rsb r1, r1, #0
rt_0200cfa8:
    adds r0, r0, r0
rt_0200cfac:
    add r2, r2, r2, lsl #1
rt_0200cfb0:
    add pc, pc, r2, lsl #2
rt_0200cfb4:
    mov r0, r0
rt_0200cfb8:
    adcs r3, r1, r3, lsl #1
rt_0200cfbc:
    sublo r3, r3, r1
rt_0200cfc0:
    adcs r0, r0, r0
rt_0200cfc4:
    adcs r3, r1, r3, lsl #1
rt_0200cfc8:
    sublo r3, r3, r1
rt_0200cfcc:
    adcs r0, r0, r0
rt_0200cfd0:
    adcs r3, r1, r3, lsl #1
rt_0200cfd4:
    sublo r3, r3, r1
rt_0200cfd8:
    adcs r0, r0, r0
rt_0200cfdc:
    adcs r3, r1, r3, lsl #1
rt_0200cfe0:
    sublo r3, r3, r1
rt_0200cfe4:
    adcs r0, r0, r0
rt_0200cfe8:
    adcs r3, r1, r3, lsl #1
rt_0200cfec:
    sublo r3, r3, r1
rt_0200cff0:
    adcs r0, r0, r0
rt_0200cff4:
    adcs r3, r1, r3, lsl #1
rt_0200cff8:
    sublo r3, r3, r1
rt_0200cffc:
    adcs r0, r0, r0
rt_0200d000:
    adcs r3, r1, r3, lsl #1
rt_0200d004:
    sublo r3, r3, r1
rt_0200d008:
    adcs r0, r0, r0
rt_0200d00c:
    adcs r3, r1, r3, lsl #1
rt_0200d010:
    sublo r3, r3, r1
rt_0200d014:
    adcs r0, r0, r0
rt_0200d018:
    adcs r3, r1, r3, lsl #1
rt_0200d01c:
    sublo r3, r3, r1
rt_0200d020:
    adcs r0, r0, r0
rt_0200d024:
    adcs r3, r1, r3, lsl #1
rt_0200d028:
    sublo r3, r3, r1
rt_0200d02c:
    adcs r0, r0, r0
rt_0200d030:
    adcs r3, r1, r3, lsl #1
rt_0200d034:
    sublo r3, r3, r1
rt_0200d038:
    adcs r0, r0, r0
rt_0200d03c:
    adcs r3, r1, r3, lsl #1
rt_0200d040:
    sublo r3, r3, r1
rt_0200d044:
    adcs r0, r0, r0
rt_0200d048:
    adcs r3, r1, r3, lsl #1
rt_0200d04c:
    sublo r3, r3, r1
rt_0200d050:
    adcs r0, r0, r0
rt_0200d054:
    adcs r3, r1, r3, lsl #1
rt_0200d058:
    sublo r3, r3, r1
rt_0200d05c:
    adcs r0, r0, r0
rt_0200d060:
    adcs r3, r1, r3, lsl #1
rt_0200d064:
    sublo r3, r3, r1
rt_0200d068:
    adcs r0, r0, r0
rt_0200d06c:
    adcs r3, r1, r3, lsl #1
rt_0200d070:
    sublo r3, r3, r1
rt_0200d074:
    adcs r0, r0, r0
rt_0200d078:
    adcs r3, r1, r3, lsl #1
rt_0200d07c:
    sublo r3, r3, r1
rt_0200d080:
    adcs r0, r0, r0
rt_0200d084:
    adcs r3, r1, r3, lsl #1
rt_0200d088:
    sublo r3, r3, r1
rt_0200d08c:
    adcs r0, r0, r0
rt_0200d090:
    adcs r3, r1, r3, lsl #1
rt_0200d094:
    sublo r3, r3, r1
rt_0200d098:
    adcs r0, r0, r0
rt_0200d09c:
    adcs r3, r1, r3, lsl #1
rt_0200d0a0:
    sublo r3, r3, r1
rt_0200d0a4:
    adcs r0, r0, r0
rt_0200d0a8:
    adcs r3, r1, r3, lsl #1
rt_0200d0ac:
    sublo r3, r3, r1
rt_0200d0b0:
    adcs r0, r0, r0
rt_0200d0b4:
    adcs r3, r1, r3, lsl #1
rt_0200d0b8:
    sublo r3, r3, r1
rt_0200d0bc:
    adcs r0, r0, r0
rt_0200d0c0:
    adcs r3, r1, r3, lsl #1
rt_0200d0c4:
    sublo r3, r3, r1
rt_0200d0c8:
    adcs r0, r0, r0
rt_0200d0cc:
    adcs r3, r1, r3, lsl #1
rt_0200d0d0:
    sublo r3, r3, r1
rt_0200d0d4:
    adcs r0, r0, r0
rt_0200d0d8:
    adcs r3, r1, r3, lsl #1
rt_0200d0dc:
    sublo r3, r3, r1
rt_0200d0e0:
    adcs r0, r0, r0
rt_0200d0e4:
    adcs r3, r1, r3, lsl #1
rt_0200d0e8:
    sublo r3, r3, r1
rt_0200d0ec:
    adcs r0, r0, r0
rt_0200d0f0:
    adcs r3, r1, r3, lsl #1
rt_0200d0f4:
    sublo r3, r3, r1
rt_0200d0f8:
    adcs r0, r0, r0
rt_0200d0fc:
    adcs r3, r1, r3, lsl #1
rt_0200d100:
    sublo r3, r3, r1
rt_0200d104:
    adcs r0, r0, r0
rt_0200d108:
    adcs r3, r1, r3, lsl #1
rt_0200d10c:
    sublo r3, r3, r1
rt_0200d110:
    adcs r0, r0, r0
rt_0200d114:
    adcs r3, r1, r3, lsl #1
rt_0200d118:
    sublo r3, r3, r1
rt_0200d11c:
    adcs r0, r0, r0
rt_0200d120:
    adcs r3, r1, r3, lsl #1
rt_0200d124:
    sublo r3, r3, r1
rt_0200d128:
    adcs r0, r0, r0
rt_0200d12c:
    adcs r3, r1, r3, lsl #1
rt_0200d130:
    sublo r3, r3, r1
rt_0200d134:
    adcs r0, r0, r0
rt_0200d138:
    mov r1, r3
rt_0200d13c:
    ands r3, r12, #0x80000000
rt_0200d140:
    rsbne r0, r0, #0
rt_0200d144:
    ands r3, r12, #1
rt_0200d148:
    rsbne r1, r1, #0
rt_0200d14c:
    bx lr
}
