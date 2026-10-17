// Compiler runtime support: _f_div, _fdiv.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_div.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_div.s.
// DQIX USA arm9/main: 0x0200C1C0, 952 bytes.
// Original bytes SHA256: ebb0569ce19f6815efb0cdcf0aafb524739ef4b6e3a6dc2092e42402ef686236.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _fdiv()
{

rt_0200c1c0:
    stmdb sp!, {lr}
rt_0200c1c4:
    mov r12, #0xff
rt_0200c1c8:
    ands r3, r12, r0, lsr #23
rt_0200c1cc:
    cmpne r3, #0xff
rt_0200c1d0:
    beq rt_0200c394
rt_0200c1d4:
    ands r12, r12, r1, lsr #23
rt_0200c1d8:
    cmpne r12, #0xff
rt_0200c1dc:
    beq rt_0200c3d0
rt_0200c1e0:
    orr r1, r1, #0x800000
rt_0200c1e4:
    orr r0, r0, #0x800000
rt_0200c1e8:
    bic r2, r0, #0xff000000
rt_0200c1ec:
    bic lr, r1, #0xff000000
rt_0200c1f0:
    cmp r2, lr
rt_0200c1f4:
    movlo r2, r2, lsl #1
rt_0200c1f8:
    sublo r3, r3, #1
rt_0200c1fc:
    teq r0, r1
rt_0200c200:
    sub r0, pc, #0x94
rt_0200c204:
    ldrb r1, [r0, lr, lsr #15]
rt_0200c208:
    rsb lr, lr, #0
rt_0200c20c:
    mov r0, lr, asr #1
rt_0200c210:
    mul r0, r1, r0
rt_0200c214:
    add r0, r0, #0x80000000
rt_0200c218:
    mov r0, r0, lsr #6
rt_0200c21c:
    mul r0, r1, r0
rt_0200c220:
    mov r0, r0, lsr #0xe
rt_0200c224:
    mul r1, lr, r0
rt_0200c228:
    sub r12, r3, r12
rt_0200c22c:
    mov r1, r1, lsr #0xc
rt_0200c230:
    mul r1, r0, r1
rt_0200c234:
    mov r0, r0, lsl #0xe
rt_0200c238:
    add r0, r0, r1, lsr #15
rt_0200c23c:
    umull r1, r0, r2, r0
rt_0200c240:
    mov r3, r0
rt_0200c244:
    orrmi r0, r0, #0x80000000
rt_0200c248:
    adds r12, r12, #0x7e
rt_0200c24c:
    bmi rt_0200c498
rt_0200c250:
    cmp r12, #0xfe
rt_0200c254:
    bge rt_0200c54c
rt_0200c258:
    add r0, r0, r12, lsl #23
rt_0200c25c:
    mov r12, r1, lsr #0x1c
rt_0200c260:
    cmp r12, #7
rt_0200c264:
    beq rt_0200c374
rt_0200c268:
    add r0, r0, r1, lsr #31
rt_0200c26c:
    ldmia sp!, {lr}
rt_0200c270:
    bx lr
rt_0200c274:
data_0200c274:
    dcd 0xfdfeffff // Literal/table data, not an instruction.
rt_0200c278:
    dcd 0xf9fafbfc // Literal/table data, not an instruction.
rt_0200c27c:
    dcd 0xf5f6f7f8 // Literal/table data, not an instruction.
rt_0200c280:
    dcd 0xf1f2f3f4 // Literal/table data, not an instruction.
rt_0200c284:
    dcd 0xeeeff0f0 // Literal/table data, not an instruction.
rt_0200c288:
    dcd 0xeaebeced // Literal/table data, not an instruction.
rt_0200c28c:
    dcd 0xe7e8e9ea // Literal/table data, not an instruction.
rt_0200c290:
    dcd 0xe4e5e6e6 // Literal/table data, not an instruction.
rt_0200c294:
    dcd 0xe1e2e2e3 // Literal/table data, not an instruction.
rt_0200c298:
    dcd 0xdedfdfe0 // Literal/table data, not an instruction.
rt_0200c29c:
    dcd 0xdbdcdcdd // Literal/table data, not an instruction.
rt_0200c2a0:
    dcd 0xd8d9d9da // Literal/table data, not an instruction.
rt_0200c2a4:
    dcd 0xd5d6d7d7 // Literal/table data, not an instruction.
rt_0200c2a8:
    dcd 0xd2d3d4d4 // Literal/table data, not an instruction.
rt_0200c2ac:
    dcd 0xd0d0d1d2 // Literal/table data, not an instruction.
rt_0200c2b0:
    dcd 0xcdcececf // Literal/table data, not an instruction.
rt_0200c2b4:
    dcd 0xcbcbcccc // Literal/table data, not an instruction.
rt_0200c2b8:
    dcd 0xc8c9c9ca // Literal/table data, not an instruction.
rt_0200c2bc:
    dcd 0xc6c6c7c8 // Literal/table data, not an instruction.
rt_0200c2c0:
    dcd 0xc3c4c5c5 // Literal/table data, not an instruction.
rt_0200c2c4:
    dcd 0xc1c2c2c3 // Literal/table data, not an instruction.
rt_0200c2c8:
    dcd 0xbfbfc0c0 // Literal/table data, not an instruction.
rt_0200c2cc:
    dcd 0xbdbdbebe // Literal/table data, not an instruction.
rt_0200c2d0:
    dcd 0xbabbbcbc // Literal/table data, not an instruction.
rt_0200c2d4:
    dcd 0xb8b9b9ba // Literal/table data, not an instruction.
rt_0200c2d8:
    dcd 0xb6b7b7b8 // Literal/table data, not an instruction.
rt_0200c2dc:
    dcd 0xb4b5b5b6 // Literal/table data, not an instruction.
rt_0200c2e0:
    dcd 0xb2b3b3b4 // Literal/table data, not an instruction.
rt_0200c2e4:
    dcd 0xb0b1b1b2 // Literal/table data, not an instruction.
rt_0200c2e8:
    dcd 0xafafafb0 // Literal/table data, not an instruction.
rt_0200c2ec:
    dcd 0xadadaeae // Literal/table data, not an instruction.
rt_0200c2f0:
    dcd 0xababacac // Literal/table data, not an instruction.
rt_0200c2f4:
    dcd 0xa9aaaaaa // Literal/table data, not an instruction.
rt_0200c2f8:
    dcd 0xa7a8a8a9 // Literal/table data, not an instruction.
rt_0200c2fc:
    dcd 0xa6a6a7a7 // Literal/table data, not an instruction.
rt_0200c300:
    dcd 0xa4a4a5a5 // Literal/table data, not an instruction.
rt_0200c304:
    dcd 0xa2a3a3a4 // Literal/table data, not an instruction.
rt_0200c308:
    dcd 0xa1a1a2a2 // Literal/table data, not an instruction.
rt_0200c30c:
    dcd 0x9fa0a0a0 // Literal/table data, not an instruction.
rt_0200c310:
    dcd 0x9e9e9e9f // Literal/table data, not an instruction.
rt_0200c314:
    dcd 0x9c9d9d9d // Literal/table data, not an instruction.
rt_0200c318:
    dcd 0x9b9b9b9c // Literal/table data, not an instruction.
rt_0200c31c:
    dcd 0x999a9a9a // Literal/table data, not an instruction.
rt_0200c320:
    dcd 0x98989999 // Literal/table data, not an instruction.
rt_0200c324:
    dcd 0x96979798 // Literal/table data, not an instruction.
rt_0200c328:
    dcd 0x95959696 // Literal/table data, not an instruction.
rt_0200c32c:
    dcd 0x94949495 // Literal/table data, not an instruction.
rt_0200c330:
    dcd 0x92939393 // Literal/table data, not an instruction.
rt_0200c334:
    dcd 0x91919292 // Literal/table data, not an instruction.
rt_0200c338:
    dcd 0x90909191 // Literal/table data, not an instruction.
rt_0200c33c:
    dcd 0x8f8f8f90 // Literal/table data, not an instruction.
rt_0200c340:
    dcd 0x8d8e8e8e // Literal/table data, not an instruction.
rt_0200c344:
    dcd 0x8c8c8d8d // Literal/table data, not an instruction.
rt_0200c348:
    dcd 0x8b8b8c8c // Literal/table data, not an instruction.
rt_0200c34c:
    dcd 0x8a8a8a8b // Literal/table data, not an instruction.
rt_0200c350:
    dcd 0x8989898a // Literal/table data, not an instruction.
rt_0200c354:
    dcd 0x88888888 // Literal/table data, not an instruction.
rt_0200c358:
    dcd 0x86878787 // Literal/table data, not an instruction.
rt_0200c35c:
    dcd 0x85868686 // Literal/table data, not an instruction.
rt_0200c360:
    dcd 0x84858585 // Literal/table data, not an instruction.
rt_0200c364:
    dcd 0x83838484 // Literal/table data, not an instruction.
rt_0200c368:
    dcd 0x82828383 // Literal/table data, not an instruction.
rt_0200c36c:
    dcd 0x81818282 // Literal/table data, not an instruction.
rt_0200c370:
    dcd 0x80808181 // Literal/table data, not an instruction.
rt_0200c374:
    mov r1, r3, lsl #1
rt_0200c378:
    add r1, r1, #1
rt_0200c37c:
    rsb lr, lr, #0
rt_0200c380:
    mul r1, lr, r1
rt_0200c384:
    cmp r1, r2, lsl #24
rt_0200c388:
    addmi r0, r0, #1
rt_0200c38c:
    ldmia sp!, {lr}
rt_0200c390:
    bx lr
rt_0200c394:
    eor lr, r0, r1
rt_0200c398:
    and lr, lr, #0x80000000
rt_0200c39c:
    cmp r3, #0
rt_0200c3a0:
    beq rt_0200c3ec
rt_0200c3a4:
    movs r0, r0, lsl #9
rt_0200c3a8:
    bne rt_0200c534
rt_0200c3ac:
    mov r12, r1, lsr #0x17
rt_0200c3b0:
    mov r1, r1, lsl #9
rt_0200c3b4:
    ands r12, r12, #0xff
rt_0200c3b8:
    beq rt_0200c524
rt_0200c3bc:
    cmp r12, #0xff
rt_0200c3c0:
    blt rt_0200c524
rt_0200c3c4:
    cmp r1, #0
rt_0200c3c8:
    beq rt_0200c540
rt_0200c3cc:
    b rt_0200c51c
rt_0200c3d0:
    eor lr, r0, r1
rt_0200c3d4:
    and lr, lr, #0x80000000
rt_0200c3d8:
    cmp r12, #0
rt_0200c3dc:
    beq rt_0200c450
rt_0200c3e0:
    movs r1, r1, lsl #9
rt_0200c3e4:
    bne rt_0200c51c
rt_0200c3e8:
    b rt_0200c56c
rt_0200c3ec:
    movs r2, r0, lsl #9
rt_0200c3f0:
    beq rt_0200c420
rt_0200c3f4:
    clz r3, r2
rt_0200c3f8:
    movs r2, r2, lsl r3
rt_0200c3fc:
    rsb r3, r3, #0
rt_0200c400:
    mov r2, r2, lsr #8
rt_0200c404:
    ands r12, r12, r1, lsr #23
rt_0200c408:
    beq rt_0200c478
rt_0200c40c:
    cmp r12, #0xff
rt_0200c410:
    beq rt_0200c3e0
rt_0200c414:
    orr r1, r1, #0x800000
rt_0200c418:
    bic lr, r1, #0xff000000
rt_0200c41c:
    b rt_0200c1f0
rt_0200c420:
    mov r12, r1, lsr #0x17
rt_0200c424:
    mov r1, r1, lsl #9
rt_0200c428:
    ands r12, r12, #0xff
rt_0200c42c:
    beq rt_0200c444
rt_0200c430:
    cmp r12, #0xff
rt_0200c434:
    blt rt_0200c56c
rt_0200c438:
    cmp r1, #0
rt_0200c43c:
    beq rt_0200c56c
rt_0200c440:
    b rt_0200c51c
rt_0200c444:
    cmp r1, #0
rt_0200c448:
    beq rt_0200c540
rt_0200c44c:
    b rt_0200c56c
rt_0200c450:
    movs r12, r1, lsl #9
rt_0200c454:
    beq rt_0200c524
rt_0200c458:
    mov lr, r12
rt_0200c45c:
    clz r12, lr
rt_0200c460:
    movs lr, lr, lsl r12
rt_0200c464:
    rsb r12, r12, #0
rt_0200c468:
    mov lr, lr, lsr #8
rt_0200c46c:
    orr r0, r0, #0x800000
rt_0200c470:
    bic r2, r0, #0xff000000
rt_0200c474:
    b rt_0200c1f0
rt_0200c478:
    movs r12, r1, lsl #9
rt_0200c47c:
    beq rt_0200c524
rt_0200c480:
    mov lr, r12
rt_0200c484:
    clz r12, lr
rt_0200c488:
    movs lr, lr, lsl r12
rt_0200c48c:
    rsb r12, r12, #0
rt_0200c490:
    mov lr, lr, lsr #8
rt_0200c494:
    b rt_0200c1f0
rt_0200c498:
    and r0, r0, #0x80000000
rt_0200c49c:
    cmn r12, #0x18
rt_0200c4a0:
    beq rt_0200c50c
rt_0200c4a4:
    bmi rt_0200c564
rt_0200c4a8:
    add r1, r12, #0x17
rt_0200c4ac:
    mov r2, r2, lsl r1
rt_0200c4b0:
    rsb r12, r12, #0
rt_0200c4b4:
    mov r3, r3, lsr r12
rt_0200c4b8:
    orr r0, r0, r3
rt_0200c4bc:
    rsb lr, lr, #0
rt_0200c4c0:
    mul r1, lr, r3
rt_0200c4c4:
    cmp r1, r2
rt_0200c4c8:
    ldmeqia sp!, {lr}
rt_0200c4cc:
    bxeq lr
rt_0200c4d0:
    add r1, r1, lr
rt_0200c4d4:
    cmp r1, r2
rt_0200c4d8:
    beq rt_0200c500
rt_0200c4dc:
    addmi r0, r0, #1
rt_0200c4e0:
    subpl r1, r1, lr
rt_0200c4e4:
    add r1, lr, r1, lsl #1
rt_0200c4e8:
    cmp r1, r2, lsl #1
rt_0200c4ec:
    and r3, r0, #1
rt_0200c4f0:
    addmi r0, r0, #1
rt_0200c4f4:
    addeq r0, r0, r3
rt_0200c4f8:
    ldmia sp!, {lr}
rt_0200c4fc:
    bx lr
rt_0200c500:
    add r0, r0, #1
rt_0200c504:
    ldmia sp!, {lr}
rt_0200c508:
    bx lr
rt_0200c50c:
    cmn r2, lr
rt_0200c510:
    addne r0, r0, #1
rt_0200c514:
    ldmia sp!, {lr}
rt_0200c518:
    bx lr
rt_0200c51c:
    mov r0, r1
rt_0200c520:
    b rt_0200c534
rt_0200c524:
    mov r0, #0xff000000
rt_0200c528:
    orr r0, lr, r0, lsr #1
rt_0200c52c:
    ldmia sp!, {lr}
rt_0200c530:
    bx lr
rt_0200c534:
    mvn r0, #0x80000000
rt_0200c538:
    ldmia sp!, {lr}
rt_0200c53c:
    bx lr
rt_0200c540:
    mvn r0, #0x80000000
rt_0200c544:
    ldmia sp!, {lr}
rt_0200c548:
    bx lr
rt_0200c54c:
    tst r0, #0x80000000
rt_0200c550:
    mov r0, #0xff000000
rt_0200c554:
    movne r0, r0, asr #1
rt_0200c558:
    moveq r0, r0, lsr #1
rt_0200c55c:
    ldmia sp!, {lr}
rt_0200c560:
    bx lr
rt_0200c564:
    ldmia sp!, {lr}
rt_0200c568:
    bx lr
rt_0200c56c:
    mov r0, lr
rt_0200c570:
    ldmia sp!, {lr}
rt_0200c574:
    bx lr
}
