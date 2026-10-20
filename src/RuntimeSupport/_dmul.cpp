// Compiler runtime support: _d_mul, _dmul.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_mul.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_mul.s.
// DQIX USA arm9/main: 0x0200B0F0, 868 bytes.
// Original bytes SHA256: 16a30a586ebe9ac165d52d79b8d6ece3be666b610328fe3fc4a778744e676c4e.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _dmul()
{

rt_0200b0f0:
    stmdb sp!, {r4, r5, r6, r7, lr}
rt_0200b0f4:
    eor lr, r1, r3
rt_0200b0f8:
    and lr, lr, #0x80000000
rt_0200b0fc:
    mov r12, r1, lsr #0x14
rt_0200b100:
    mov r1, r1, lsl #0xb
rt_0200b104:
    orr r1, r1, r0, lsr #21
rt_0200b108:
    mov r0, r0, lsl #0xb
rt_0200b10c:
    movs r6, r12, lsl #0x15
rt_0200b110:
    cmnne r6, #0x200000
rt_0200b114:
    beq rt_0200b1f8
rt_0200b118:
    orr r1, r1, #0x80000000
rt_0200b11c:
    bic r12, r12, #0x800
rt_0200b120:
    mov r4, r3, lsr #0x14
rt_0200b124:
    mov r3, r3, lsl #0xb
rt_0200b128:
    orr r3, r3, r2, lsr #21
rt_0200b12c:
    mov r2, r2, lsl #0xb
rt_0200b130:
    movs r5, r4, lsl #0x15
rt_0200b134:
    cmnne r5, #0x200000
rt_0200b138:
    beq rt_0200b240
rt_0200b13c:
    orr r3, r3, #0x80000000
rt_0200b140:
    bic r4, r4, #0x800
rt_0200b144:
    add r12, r4, r12
rt_0200b148:
    umull r5, r4, r0, r2
rt_0200b14c:
    umull r7, r6, r0, r3
rt_0200b150:
    adds r4, r7, r4
rt_0200b154:
    adc r6, r6, #0
rt_0200b158:
    umull r7, r0, r1, r2
rt_0200b15c:
    adds r4, r7, r4
rt_0200b160:
    adcs r0, r0, r6
rt_0200b164:
    umull r7, r2, r1, r3
rt_0200b168:
    adc r1, r2, #0
rt_0200b16c:
    adds r0, r0, r7
rt_0200b170:
    adc r1, r1, #0
rt_0200b174:
    orrs r4, r4, r5
rt_0200b178:
    orrne r0, r0, #1
rt_0200b17c:
    cmp r1, #0
rt_0200b180:
    blt rt_0200b190
rt_0200b184:
    sub r12, r12, #1
rt_0200b188:
    adds r0, r0, r0
rt_0200b18c:
    adc r1, r1, r1
rt_0200b190:
    add r12, r12, #2
rt_0200b194:
    subs r12, r12, #0x400
rt_0200b198:
    bmi rt_0200b32c
rt_0200b19c:
    beq rt_0200b32c
rt_0200b1a0:
    mov r6, r12, lsl #0x14
rt_0200b1a4:
    cmn r6, #0x100000
rt_0200b1a8:
    bmi rt_0200b42c
rt_0200b1ac:
    movs r2, r0, lsl #0x15
rt_0200b1b0:
    mov r0, r0, lsr #0xb
rt_0200b1b4:
    orr r0, r0, r1, lsl #21
rt_0200b1b8:
    add r1, r1, r1
rt_0200b1bc:
    orr r1, lr, r1, lsr #12
rt_0200b1c0:
    orr r1, r1, r12, lsl #20
rt_0200b1c4:
    ldmeqia sp!, {r4, r5, r6, r7, lr}
rt_0200b1c8:
    bxeq lr
rt_0200b1cc:
    tst r2, #0x80000000
rt_0200b1d0:
    ldmeqia sp!, {r4, r5, r6, r7, lr}
rt_0200b1d4:
    bxeq lr
rt_0200b1d8:
    movs r2, r2, lsl #1
rt_0200b1dc:
    andeqs r2, r0, #1
rt_0200b1e0:
    ldmeqia sp!, {r4, r5, r6, r7, lr}
rt_0200b1e4:
    bxeq lr
rt_0200b1e8:
    adds r0, r0, #1
rt_0200b1ec:
    adc r1, r1, #0
rt_0200b1f0:
    ldmia sp!, {r4, r5, r6, r7, lr}
rt_0200b1f4:
    bx lr
rt_0200b1f8:
    bics r12, r12, #0x800
rt_0200b1fc:
    beq rt_0200b254
rt_0200b200:
    orrs r6, r0, r1, lsl #1
rt_0200b204:
    bne rt_0200b3e0
rt_0200b208:
    mov r4, r3, lsr #0x14
rt_0200b20c:
    mov r3, r3, lsl #0xb
rt_0200b210:
    orr r3, r3, r2, lsr #21
rt_0200b214:
    mov r2, r2, lsl #0xb
rt_0200b218:
    movs r5, r4, lsl #0x15
rt_0200b21c:
    beq rt_0200b234
rt_0200b220:
    cmn r5, #0x200000
rt_0200b224:
    bne rt_0200b3cc
rt_0200b228:
    orrs r5, r2, r3, lsl #1
rt_0200b22c:
    beq rt_0200b3cc
rt_0200b230:
    b rt_0200b3e0
rt_0200b234:
    orrs r5, r3, r2
rt_0200b238:
    beq rt_0200b3f4
rt_0200b23c:
    b rt_0200b3cc
rt_0200b240:
    bics r4, r4, #0x800
rt_0200b244:
    beq rt_0200b2e8
rt_0200b248:
    orrs r6, r2, r3, lsl #1
rt_0200b24c:
    bne rt_0200b3e0
rt_0200b250:
    b rt_0200b3cc
rt_0200b254:
    orrs r6, r0, r1, lsl #1
rt_0200b258:
    beq rt_0200b2bc
rt_0200b25c:
    mov r12, #1
rt_0200b260:
    cmp r1, #0
rt_0200b264:
    bne rt_0200b278
rt_0200b268:
    sub r12, r12, #0x20
rt_0200b26c:
    movs r1, r0
rt_0200b270:
    mov r0, #0
rt_0200b274:
    bmi rt_0200b294
rt_0200b278:
    clz r6, r1
rt_0200b27c:
    movs r1, r1, lsl r6
rt_0200b280:
    rsb r6, r6, #0x20
rt_0200b284:
    orr r1, r1, r0, lsr r6
rt_0200b288:
    rsb r6, r6, #0x20
rt_0200b28c:
    mov r0, r0, lsl r6
rt_0200b290:
    sub r12, r12, r6
rt_0200b294:
    mov r4, r3, lsr #0x14
rt_0200b298:
    mov r3, r3, lsl #0xb
rt_0200b29c:
    orr r3, r3, r2, lsr #21
rt_0200b2a0:
    mov r2, r2, lsl #0xb
rt_0200b2a4:
    movs r5, r4, lsl #0x15
rt_0200b2a8:
    cmnne r5, #0x200000
rt_0200b2ac:
    beq rt_0200b240
rt_0200b2b0:
    orr r3, r3, #0x80000000
rt_0200b2b4:
    bic r4, r4, #0x800
rt_0200b2b8:
    b rt_0200b144
rt_0200b2bc:
    mov r4, r3, lsr #0x14
rt_0200b2c0:
    mov r3, r3, lsl #0xb
rt_0200b2c4:
    orr r3, r3, r2, lsr #21
rt_0200b2c8:
    mov r2, r2, lsl #0xb
rt_0200b2cc:
    movs r5, r4, lsl #0x15
rt_0200b2d0:
    beq rt_0200b440
rt_0200b2d4:
    cmn r5, #0x200000
rt_0200b2d8:
    bne rt_0200b440
rt_0200b2dc:
    orrs r6, r2, r3, lsl #1
rt_0200b2e0:
    beq rt_0200b3f4
rt_0200b2e4:
    b rt_0200b3e0
rt_0200b2e8:
    orrs r5, r2, r3, lsl #1
rt_0200b2ec:
    beq rt_0200b440
rt_0200b2f0:
    mov r4, #1
rt_0200b2f4:
    cmp r3, #0
rt_0200b2f8:
    bne rt_0200b30c
rt_0200b2fc:
    sub r4, r4, #0x20
rt_0200b300:
    movs r3, r2
rt_0200b304:
    mov r2, #0
rt_0200b308:
    bmi rt_0200b144
rt_0200b30c:
    clz r6, r3
rt_0200b310:
    movs r3, r3, lsl r6
rt_0200b314:
    rsb r6, r6, #0x20
rt_0200b318:
    orr r3, r3, r2, lsr r6
rt_0200b31c:
    rsb r6, r6, #0x20
rt_0200b320:
    mov r2, r2, lsl r6
rt_0200b324:
    sub r4, r4, r6
rt_0200b328:
    b rt_0200b144
rt_0200b32c:
    cmn r12, #0x34
rt_0200b330:
    beq rt_0200b3c4
rt_0200b334:
    bmi rt_0200b41c
rt_0200b338:
    mov r2, r1
rt_0200b33c:
    mov r3, r0
rt_0200b340:
    add r4, r12, #0x34
rt_0200b344:
    cmp r4, #0x20
rt_0200b348:
    movge r2, r3
rt_0200b34c:
    movge r3, #0
rt_0200b350:
    subge r4, r4, #0x20
rt_0200b354:
    rsb r5, r4, #0x20
rt_0200b358:
    mov r2, r2, lsl r4
rt_0200b35c:
    orr r2, r2, r3, lsr r5
rt_0200b360:
    movs r3, r3, lsl r4
rt_0200b364:
    orrne r2, r2, #1
rt_0200b368:
    rsb r12, r12, #0xc
rt_0200b36c:
    cmp r12, #0x20
rt_0200b370:
    movge r0, r1
rt_0200b374:
    movge r1, #0
rt_0200b378:
    subge r12, r12, #0x20
rt_0200b37c:
    rsb r4, r12, #0x20
rt_0200b380:
    mov r0, r0, lsr r12
rt_0200b384:
    orr r0, r0, r1, lsl r4
rt_0200b388:
    orr r1, lr, r1, lsr r12
rt_0200b38c:
    cmp r2, #0
rt_0200b390:
    ldmeqia sp!, {r4, r5, r6, r7, lr}
rt_0200b394:
    bxeq lr
rt_0200b398:
    tst r2, #0x80000000
rt_0200b39c:
    ldmeqia sp!, {r4, r5, r6, r7, lr}
rt_0200b3a0:
    bxeq lr
rt_0200b3a4:
    movs r2, r2, lsl #1
rt_0200b3a8:
    andeqs r2, r0, #1
rt_0200b3ac:
    ldmeqia sp!, {r4, r5, r6, r7, lr}
rt_0200b3b0:
    bxeq lr
rt_0200b3b4:
    adds r0, r0, #1
rt_0200b3b8:
    adc r1, r1, #0
rt_0200b3bc:
    ldmia sp!, {r4, r5, r6, r7, lr}
rt_0200b3c0:
    bx lr
rt_0200b3c4:
    orr r0, r0, r1, lsl #1
rt_0200b3c8:
    b rt_0200b404
rt_0200b3cc:
    ldr r1, [pc, #124] // Literal at 0x0200b450
rt_0200b3d0:
    orr r1, lr, r1
rt_0200b3d4:
    mov r0, #0
rt_0200b3d8:
    ldmia sp!, {r4, r5, r6, r7, lr}
rt_0200b3dc:
    bx lr
rt_0200b3e0:
    mov r1, r3
rt_0200b3e4:
    mvn r0, #0
rt_0200b3e8:
    bic r1, r0, #0x80000000
rt_0200b3ec:
    ldmia sp!, {r4, r5, r6, r7, lr}
rt_0200b3f0:
    bx lr
rt_0200b3f4:
    mvn r0, #0
rt_0200b3f8:
    bic r1, r0, #0x80000000
rt_0200b3fc:
    ldmia sp!, {r4, r5, r6, r7, lr}
rt_0200b400:
    bx lr
rt_0200b404:
    movs r2, r0
rt_0200b408:
    mov r1, lr
rt_0200b40c:
    mov r0, #0
rt_0200b410:
    addne r0, r0, #1
rt_0200b414:
    ldmia sp!, {r4, r5, r6, r7, lr}
rt_0200b418:
    bx lr
rt_0200b41c:
    mov r1, lr
rt_0200b420:
    mov r0, #0
rt_0200b424:
    ldmia sp!, {r4, r5, r6, r7, lr}
rt_0200b428:
    bx lr
rt_0200b42c:
    ldr r1, [pc, #28] // Literal at 0x0200b450
rt_0200b430:
    orr r1, lr, r1
rt_0200b434:
    mov r0, #0
rt_0200b438:
    ldmia sp!, {r4, r5, r6, r7, lr}
rt_0200b43c:
    bx lr
rt_0200b440:
    mov r1, lr
rt_0200b444:
    mov r0, #0
rt_0200b448:
    ldmia sp!, {r4, r5, r6, r7, lr}
rt_0200b44c:
    bx lr
rt_0200b450:
    dcd 0x7ff00000 // Literal/table data, not an instruction.
}
