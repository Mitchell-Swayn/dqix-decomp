// Compiler runtime support: __throw_catch_compare.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Runtime/Runtime_ARM/Runtime_NITRO/Lib/NITRO_Runtime_Ai_LE.a. Object: mwexception.o.
// Original vendor source: not recorded in object.
// DQIX USA arm9/main: 0x0200EFF0, 432 bytes.
// Original bytes SHA256: 4c15dc90f41e09d74477d9e23386e1d5cfe0a292aa3e0d86c992613a0a7a95ae.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void __throw_catch_compare()
{

rt_0200eff0:
    stmdb sp!, {r3, lr}
rt_0200eff4:
    mov r12, #0
rt_0200eff8:
    mov r3, r1
rt_0200effc:
    cmp r1, #0
rt_0200f000:
    str r12, [r2]
rt_0200f004:
    moveq r0, #1
rt_0200f008:
    ldmeqia sp!, {r3, pc}
rt_0200f00c:
    ldrb r12, [r1]
rt_0200f010:
    cmp r12, #0x50
rt_0200f014:
    bne rt_0200f054
rt_0200f018:
    ldrb r12, [r3, #1]!
rt_0200f01c:
    cmp r12, #0x56
rt_0200f020:
    addeq r3, r3, #1
rt_0200f024:
    ldrb r12, [r3]
rt_0200f028:
    cmp r12, #0x4b
rt_0200f02c:
    addeq r3, r3, #1
rt_0200f030:
    ldrb r3, [r3]
rt_0200f034:
    cmp r3, #0x76
rt_0200f038:
    bne rt_0200f050
rt_0200f03c:
    ldrb r3, [r0]
rt_0200f040:
    cmp r3, #0x50
rt_0200f044:
    cmpne r3, #0x2a
rt_0200f048:
    moveq r0, #1
rt_0200f04c:
    ldmeqia sp!, {r3, pc}
rt_0200f050:
    mov r3, r1
rt_0200f054:
    ldrb r12, [r0]
rt_0200f058:
    cmp r12, #0x21
rt_0200f05c:
    cmpne r12, #0x2a
rt_0200f060:
    bne rt_0200f154
rt_0200f064:
    ldrb lr, [r0], #1
rt_0200f068:
    ldrb r12, [r3], #1
rt_0200f06c:
    cmp lr, r12
rt_0200f070:
    movne r0, #0
rt_0200f074:
    ldmneia sp!, {r3, pc}
rt_0200f078:
    ldrb lr, [r0]
rt_0200f07c:
    ldrb r12, [r3], #1
rt_0200f080:
    cmp lr, r12
rt_0200f084:
    bne rt_0200f0cc
rt_0200f088:
    cmp lr, #0x21
rt_0200f08c:
    add r0, r0, #1
rt_0200f090:
    bne rt_0200f078
rt_0200f094:
    ldrb r1, [r0]
rt_0200f098:
    mov lr, #0
rt_0200f09c:
    cmp r1, #0x21
rt_0200f0a0:
    beq rt_0200f0c0
rt_0200f0a4:
    mov r1, #0xa
rt_0200f0a8:
    ldrb r12, [r0]
rt_0200f0ac:
    ldrb r3, [r0, #1]!
rt_0200f0b0:
    mla r12, lr, r1, r12
rt_0200f0b4:
    cmp r3, #0x21
rt_0200f0b8:
    sub lr, r12, #0x30
rt_0200f0bc:
    bne rt_0200f0a8
rt_0200f0c0:
    str lr, [r2]
rt_0200f0c4:
    mov r0, #1
rt_0200f0c8:
    ldmia sp!, {r3, pc}
rt_0200f0cc:
    ldrb r3, [r0], #1
rt_0200f0d0:
    cmp r3, #0x21
rt_0200f0d4:
    bne rt_0200f0cc
rt_0200f0d8:
    ldrb r3, [r0], #1
rt_0200f0dc:
    cmp r3, #0x21
rt_0200f0e0:
    bne rt_0200f0d8
rt_0200f0e4:
    ldrb r3, [r0]
rt_0200f0e8:
    cmp r3, #0
rt_0200f0ec:
    moveq r0, #0
rt_0200f0f0:
    ldmeqia sp!, {r3, pc}
rt_0200f0f4:
    add r3, r1, #1
rt_0200f0f8:
    b rt_0200f078
rt_0200f0fc:
    ldrb r1, [r3, #1]!
rt_0200f100:
    add r0, r0, #1
rt_0200f104:
    cmp r1, #0x4b
rt_0200f108:
    bne rt_0200f11c
rt_0200f10c:
    ldrb r1, [r0]
rt_0200f110:
    add r3, r3, #1
rt_0200f114:
    cmp r1, #0x4b
rt_0200f118:
    addeq r0, r0, #1
rt_0200f11c:
    ldrb r2, [r0]
rt_0200f120:
    cmp r2, #0x4b
rt_0200f124:
    moveq r0, #0
rt_0200f128:
    ldmeqia sp!, {r3, pc}
rt_0200f12c:
    ldrb r1, [r3]
rt_0200f130:
    cmp r1, #0x56
rt_0200f134:
    bne rt_0200f144
rt_0200f138:
    cmp r2, #0x56
rt_0200f13c:
    addeq r0, r0, #1
rt_0200f140:
    add r3, r3, #1
rt_0200f144:
    ldrb r1, [r0]
rt_0200f148:
    cmp r1, #0x56
rt_0200f14c:
    moveq r0, #0
rt_0200f150:
    ldmeqia sp!, {r3, pc}
rt_0200f154:
    ldrb r2, [r0]
rt_0200f158:
    cmp r2, #0x50
rt_0200f15c:
    cmpne r2, #0x52
rt_0200f160:
    bne rt_0200f170
rt_0200f164:
    ldrb r1, [r3]
rt_0200f168:
    cmp r2, r1
rt_0200f16c:
    beq rt_0200f0fc
rt_0200f170:
    ldrb r1, [r3]
rt_0200f174:
    cmp r2, r1
rt_0200f178:
    bne rt_0200f198
rt_0200f17c:
    cmp r2, #0
rt_0200f180:
    moveq r0, #1
rt_0200f184:
    ldmeqia sp!, {r3, pc}
rt_0200f188:
    ldrb r2, [r0, #1]!
rt_0200f18c:
    ldrb r1, [r3, #1]!
rt_0200f190:
    cmp r2, r1
rt_0200f194:
    beq rt_0200f17c
rt_0200f198:
    mov r0, #0
rt_0200f19c:
    ldmia sp!, {r3, pc}
}
