// Compiler runtime support: _d_div, _ddiv.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_div.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_div.s.
// DQIX USA arm9/main: 0x0200D34C, 1348 bytes.
// Original bytes SHA256: 7149929ee02390c1ba274df15d3864c58fde29827f500330717cc0391376a559.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _ddiv()
{

rt_0200d34c:
    stmdb sp!, {r4, r5, r6, lr}
rt_0200d350:
    ldr lr, [pc, #1332] // Literal at 0x0200d88c
rt_0200d354:
    eor r4, r1, r3
rt_0200d358:
    ands r12, lr, r1, lsr #19
rt_0200d35c:
    cmpne r12, lr
rt_0200d360:
    beq rt_0200d6f8
rt_0200d364:
    bic r1, r1, lr, lsl #20
rt_0200d368:
    orr r1, r1, #0x100000
rt_0200d36c:
    add r12, r12, r4, lsr #31
rt_0200d370:
    ands r4, lr, r3, lsr #19
rt_0200d374:
    cmpne r4, lr
rt_0200d378:
    beq rt_0200d790
rt_0200d37c:
    bic r3, r3, lr, lsl #20
rt_0200d380:
    orr r3, r3, #0x100000
rt_0200d384:
    sub r12, r12, r4
rt_0200d388:
    cmp r1, r3
rt_0200d38c:
    cmpeq r0, r2
rt_0200d390:
    bhs rt_0200d3a0
rt_0200d394:
    adds r0, r0, r0
rt_0200d398:
    adc r1, r1, r1
rt_0200d39c:
    sub r12, r12, #2
rt_0200d3a0:
    sub r4, pc, #0x24
rt_0200d3a4:
    ldrb lr, [r4, r3, lsr #12]
rt_0200d3a8:
    rsbs r2, r2, #0
rt_0200d3ac:
    rsc r3, r3, #0
rt_0200d3b0:
    mov r4, #0x20000000
rt_0200d3b4:
    mla r5, lr, r3, r4
rt_0200d3b8:
    mov r6, r3, lsl #0xa
rt_0200d3bc:
    mov r5, r5, lsr #7
rt_0200d3c0:
    mul lr, r5, lr
rt_0200d3c4:
    orr r6, r6, r2, lsr #22
rt_0200d3c8:
    mov lr, lr, lsr #0xd
rt_0200d3cc:
    mul r5, lr, r6
rt_0200d3d0:
    mov r6, r1, lsl #0xa
rt_0200d3d4:
    orr r6, r6, r0, lsr #22
rt_0200d3d8:
    mov r5, r5, lsr #0x10
rt_0200d3dc:
    mul r5, lr, r5
rt_0200d3e0:
    mov lr, lr, lsl #0xe
rt_0200d3e4:
    add lr, lr, r5, lsr #16
rt_0200d3e8:
    umull r5, r6, lr, r6
rt_0200d3ec:
    umull r4, r5, r6, r2
rt_0200d3f0:
    mla r5, r3, r6, r5
rt_0200d3f4:
    mov r4, r4, lsr #0x1a
rt_0200d3f8:
    orr r4, r4, r5, lsl #6
rt_0200d3fc:
    add r4, r4, r0, lsl #2
rt_0200d400:
    umull lr, r5, r4, lr
rt_0200d404:
    mov r4, #0
rt_0200d408:
    adds r5, r5, r6, lsl #24
rt_0200d40c:
    adc r4, r4, r6, lsr #8
rt_0200d410:
    cmp r12, #0x800
rt_0200d414:
    bge rt_0200d584
rt_0200d418:
    add r12, r12, #0x7f0
rt_0200d41c:
    adds r12, r12, #0xc
rt_0200d420:
    bmi rt_0200d59c
rt_0200d424:
    orr r1, r4, r12, lsl #31
rt_0200d428:
    bic r12, r12, #1
rt_0200d42c:
    add r1, r1, r12, lsl #19
rt_0200d430:
    tst lr, #0x80000000
rt_0200d434:
    bne rt_0200d474
rt_0200d438:
    rsbs r2, r2, #0
rt_0200d43c:
    mov r4, r4, lsl #1
rt_0200d440:
    add r4, r4, r5, lsr #31
rt_0200d444:
    mul lr, r2, r4
rt_0200d448:
    mov r6, #0
rt_0200d44c:
    mov r4, r5, lsl #1
rt_0200d450:
    orr r4, r4, #1
rt_0200d454:
    umlal r6, lr, r4, r2
rt_0200d458:
    rsc r3, r3, #0
rt_0200d45c:
    mla lr, r4, r3, lr
rt_0200d460:
    cmp lr, r0, lsl #21
rt_0200d464:
    bmi rt_0200d474
rt_0200d468:
    mov r0, r5
rt_0200d46c:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d470:
    bx lr
rt_0200d474:
    adds r0, r5, #1
rt_0200d478:
    adc r1, r1, #0
rt_0200d47c:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d480:
    bx lr
rt_0200d484:
data_0200d484:
    dcd 0xfdfeffff // Literal/table data, not an instruction.
rt_0200d488:
    dcd 0xf9fafbfc // Literal/table data, not an instruction.
rt_0200d48c:
    dcd 0xf5f6f7f8 // Literal/table data, not an instruction.
rt_0200d490:
    dcd 0xf1f2f3f4 // Literal/table data, not an instruction.
rt_0200d494:
    dcd 0xeeeff0f0 // Literal/table data, not an instruction.
rt_0200d498:
    dcd 0xeaebeced // Literal/table data, not an instruction.
rt_0200d49c:
    dcd 0xe7e8e9ea // Literal/table data, not an instruction.
rt_0200d4a0:
    dcd 0xe4e5e6e6 // Literal/table data, not an instruction.
rt_0200d4a4:
    dcd 0xe1e2e2e3 // Literal/table data, not an instruction.
rt_0200d4a8:
    dcd 0xdedfdfe0 // Literal/table data, not an instruction.
rt_0200d4ac:
    dcd 0xdbdcdcdd // Literal/table data, not an instruction.
rt_0200d4b0:
    dcd 0xd8d9d9da // Literal/table data, not an instruction.
rt_0200d4b4:
    dcd 0xd5d6d7d7 // Literal/table data, not an instruction.
rt_0200d4b8:
    dcd 0xd2d3d4d4 // Literal/table data, not an instruction.
rt_0200d4bc:
    dcd 0xd0d0d1d2 // Literal/table data, not an instruction.
rt_0200d4c0:
    dcd 0xcdcececf // Literal/table data, not an instruction.
rt_0200d4c4:
    dcd 0xcbcbcccc // Literal/table data, not an instruction.
rt_0200d4c8:
    dcd 0xc8c9c9ca // Literal/table data, not an instruction.
rt_0200d4cc:
    dcd 0xc6c6c7c8 // Literal/table data, not an instruction.
rt_0200d4d0:
    dcd 0xc3c4c5c5 // Literal/table data, not an instruction.
rt_0200d4d4:
    dcd 0xc1c2c2c3 // Literal/table data, not an instruction.
rt_0200d4d8:
    dcd 0xbfbfc0c0 // Literal/table data, not an instruction.
rt_0200d4dc:
    dcd 0xbdbdbebe // Literal/table data, not an instruction.
rt_0200d4e0:
    dcd 0xbabbbcbc // Literal/table data, not an instruction.
rt_0200d4e4:
    dcd 0xb8b9b9ba // Literal/table data, not an instruction.
rt_0200d4e8:
    dcd 0xb6b7b7b8 // Literal/table data, not an instruction.
rt_0200d4ec:
    dcd 0xb4b5b5b6 // Literal/table data, not an instruction.
rt_0200d4f0:
    dcd 0xb2b3b3b4 // Literal/table data, not an instruction.
rt_0200d4f4:
    dcd 0xb0b1b1b2 // Literal/table data, not an instruction.
rt_0200d4f8:
    dcd 0xafafafb0 // Literal/table data, not an instruction.
rt_0200d4fc:
    dcd 0xadadaeae // Literal/table data, not an instruction.
rt_0200d500:
    dcd 0xababacac // Literal/table data, not an instruction.
rt_0200d504:
    dcd 0xa9aaaaaa // Literal/table data, not an instruction.
rt_0200d508:
    dcd 0xa7a8a8a9 // Literal/table data, not an instruction.
rt_0200d50c:
    dcd 0xa6a6a7a7 // Literal/table data, not an instruction.
rt_0200d510:
    dcd 0xa4a4a5a5 // Literal/table data, not an instruction.
rt_0200d514:
    dcd 0xa2a3a3a4 // Literal/table data, not an instruction.
rt_0200d518:
    dcd 0xa1a1a2a2 // Literal/table data, not an instruction.
rt_0200d51c:
    dcd 0x9fa0a0a0 // Literal/table data, not an instruction.
rt_0200d520:
    dcd 0x9e9e9e9f // Literal/table data, not an instruction.
rt_0200d524:
    dcd 0x9c9d9d9d // Literal/table data, not an instruction.
rt_0200d528:
    dcd 0x9b9b9b9c // Literal/table data, not an instruction.
rt_0200d52c:
    dcd 0x999a9a9a // Literal/table data, not an instruction.
rt_0200d530:
    dcd 0x98989999 // Literal/table data, not an instruction.
rt_0200d534:
    dcd 0x96979798 // Literal/table data, not an instruction.
rt_0200d538:
    dcd 0x95959696 // Literal/table data, not an instruction.
rt_0200d53c:
    dcd 0x94949495 // Literal/table data, not an instruction.
rt_0200d540:
    dcd 0x92939393 // Literal/table data, not an instruction.
rt_0200d544:
    dcd 0x91919292 // Literal/table data, not an instruction.
rt_0200d548:
    dcd 0x90909191 // Literal/table data, not an instruction.
rt_0200d54c:
    dcd 0x8f8f8f90 // Literal/table data, not an instruction.
rt_0200d550:
    dcd 0x8d8e8e8e // Literal/table data, not an instruction.
rt_0200d554:
    dcd 0x8c8c8d8d // Literal/table data, not an instruction.
rt_0200d558:
    dcd 0x8b8b8c8c // Literal/table data, not an instruction.
rt_0200d55c:
    dcd 0x8a8a8a8b // Literal/table data, not an instruction.
rt_0200d560:
    dcd 0x8989898a // Literal/table data, not an instruction.
rt_0200d564:
    dcd 0x88888888 // Literal/table data, not an instruction.
rt_0200d568:
    dcd 0x86878787 // Literal/table data, not an instruction.
rt_0200d56c:
    dcd 0x85868686 // Literal/table data, not an instruction.
rt_0200d570:
    dcd 0x84858585 // Literal/table data, not an instruction.
rt_0200d574:
    dcd 0x83838484 // Literal/table data, not an instruction.
rt_0200d578:
    dcd 0x82828383 // Literal/table data, not an instruction.
rt_0200d57c:
    dcd 0x81818282 // Literal/table data, not an instruction.
rt_0200d580:
    dcd 0x80808181 // Literal/table data, not an instruction.
rt_0200d584:
    movs r1, r12, lsl #0x1f
rt_0200d588:
    orr r1, r1, #0x7f000000
rt_0200d58c:
    orr r1, r1, #0xf00000
rt_0200d590:
    mov r0, #0
rt_0200d594:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d598:
    bx lr
rt_0200d59c:
    mvn r6, r12, asr #1
rt_0200d5a0:
    cmp r6, #0x34
rt_0200d5a4:
    bgt rt_0200d6e8
rt_0200d5a8:
    beq rt_0200d6c4
rt_0200d5ac:
    cmp r6, #0x14
rt_0200d5b0:
    bge rt_0200d5e4
rt_0200d5b4:
    rsb r6, r6, #0x13
rt_0200d5b8:
    mov lr, r0, lsl r6
rt_0200d5bc:
    rsb r6, r6, #0x14
rt_0200d5c0:
    mov r0, r5, lsr r6
rt_0200d5c4:
    rsb r6, r6, #0x20
rt_0200d5c8:
    orr r0, r0, r4, lsl r6
rt_0200d5cc:
    rsb r6, r6, #0x20
rt_0200d5d0:
    mov r4, r4, lsr r6
rt_0200d5d4:
    orr r1, r4, r12, lsl #31
rt_0200d5d8:
    mov r12, lr
rt_0200d5dc:
    mov lr, #0
rt_0200d5e0:
    b rt_0200d614
rt_0200d5e4:
    rsb r6, r6, #0x33
rt_0200d5e8:
    mov lr, r1, lsl r6
rt_0200d5ec:
    mov r1, r12, lsl #0x1f
rt_0200d5f0:
    rsb r6, r6, #0x20
rt_0200d5f4:
    orr r12, lr, r0, lsr r6
rt_0200d5f8:
    rsb r6, r6, #0x20
rt_0200d5fc:
    mov lr, r0, lsl r6
rt_0200d600:
    mov r5, r5, lsr #0x15
rt_0200d604:
    orr r5, r5, r4, lsl #11
rt_0200d608:
    rsb r6, r6, #0x1f
rt_0200d60c:
    mov r0, r5, lsr r6
rt_0200d610:
    mov r4, #0
rt_0200d614:
    rsbs r2, r2, #0
rt_0200d618:
    mul r4, r2, r4
rt_0200d61c:
    mov r5, #0
rt_0200d620:
    umlal r5, r4, r2, r0
rt_0200d624:
    rsc r3, r3, #0
rt_0200d628:
    mla r4, r0, r3, r4
rt_0200d62c:
    cmp r4, r12
rt_0200d630:
    cmpeq r5, lr
rt_0200d634:
    ldmeqia sp!, {r4, r5, r6, lr}
rt_0200d638:
    bxeq lr
rt_0200d63c:
    adds r5, r5, r2
rt_0200d640:
    adc r4, r4, r3
rt_0200d644:
    cmp r4, r12
rt_0200d648:
    bmi rt_0200d6b8
rt_0200d64c:
    bne rt_0200d65c
rt_0200d650:
    cmp r5, lr
rt_0200d654:
    beq rt_0200d6a8
rt_0200d658:
    blo rt_0200d6b8
rt_0200d65c:
    subs r5, r5, r2
rt_0200d660:
    sbc r4, r4, r3
rt_0200d664:
    adds r5, r5, r5
rt_0200d668:
    adc r4, r4, r4
rt_0200d66c:
    adds r5, r5, r2
rt_0200d670:
    adc r4, r4, r3
rt_0200d674:
    adds lr, lr, lr
rt_0200d678:
    adc r12, r12, r12
rt_0200d67c:
    cmp r4, r12
rt_0200d680:
    bmi rt_0200d6a8
rt_0200d684:
    ldmneia sp!, {r4, r5, r6, lr}
rt_0200d688:
    bxne lr
rt_0200d68c:
    cmp r5, lr
rt_0200d690:
    blo rt_0200d6a8
rt_0200d694:
    ldmneia sp!, {r4, r5, r6, lr}
rt_0200d698:
    bxne lr
rt_0200d69c:
    tst r0, #1
rt_0200d6a0:
    ldmeqia sp!, {r4, r5, r6, lr}
rt_0200d6a4:
    bxeq lr
rt_0200d6a8:
    adds r0, r0, #1
rt_0200d6ac:
    adc r1, r1, #0
rt_0200d6b0:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d6b4:
    bx lr
rt_0200d6b8:
    adds r0, r0, #1
rt_0200d6bc:
    adc r1, r1, #0
rt_0200d6c0:
    b rt_0200d664
rt_0200d6c4:
    rsbs r2, r2, #0
rt_0200d6c8:
    rsc r3, r3, #0
rt_0200d6cc:
    cmp r1, r3
rt_0200d6d0:
    cmpeq r0, r2
rt_0200d6d4:
    mov r1, r12, lsl #0x1f
rt_0200d6d8:
    mov r0, #0
rt_0200d6dc:
    movne r0, #1
rt_0200d6e0:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d6e4:
    bx lr
rt_0200d6e8:
    mov r1, r12, lsl #0x1f
rt_0200d6ec:
    mov r0, #0
rt_0200d6f0:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d6f4:
    bx lr
rt_0200d6f8:
    orrs r5, r0, r1, lsl #1
rt_0200d6fc:
    beq rt_0200d81c
rt_0200d700:
    cmp r12, lr
rt_0200d704:
    beq rt_0200d760
rt_0200d708:
    movs r1, r1, lsl #0xc
rt_0200d70c:
    beq rt_0200d73c
rt_0200d710:
    clz r5, r1
rt_0200d714:
    movs r1, r1, lsl r5
rt_0200d718:
    sub r12, r12, r5
rt_0200d71c:
    add r5, r12, #0x1f
rt_0200d720:
    mov r1, r1, lsr #0xb
rt_0200d724:
    orr r1, r1, r0, lsr r5
rt_0200d728:
    rsb r5, r5, #0x20
rt_0200d72c:
    mov r0, r0, lsl r5
rt_0200d730:
    mov r12, r12, lsl #1
rt_0200d734:
    orr r12, r12, r4, lsr #31
rt_0200d738:
    b rt_0200d370
rt_0200d73c:
    mvn r12, #0x13
rt_0200d740:
    clz r5, r0
rt_0200d744:
    movs r0, r0, lsl r5
rt_0200d748:
    sub r12, r12, r5
rt_0200d74c:
    mov r1, r0, lsr #0xb
rt_0200d750:
    mov r0, r0, lsl #0x15
rt_0200d754:
    mov r12, r12, lsl #1
rt_0200d758:
    orr r12, r12, r4, lsr #31
rt_0200d75c:
    b rt_0200d370
rt_0200d760:
    orrs r5, r0, r1, lsl #12
rt_0200d764:
    bne rt_0200d844
rt_0200d768:
    bic r5, r3, #0x80000000
rt_0200d76c:
    cmp r5, lr, lsl #19
rt_0200d770:
    bhs rt_0200d784
rt_0200d774:
    and r5, r3, #0x80000000
rt_0200d778:
    eor r1, r5, r1
rt_0200d77c:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d780:
    bx lr
rt_0200d784:
    orrs r5, r2, r3, lsl #12
rt_0200d788:
    bne rt_0200d864
rt_0200d78c:
    b rt_0200d87c
rt_0200d790:
    orrs r5, r2, r3, lsl #1
rt_0200d794:
    beq rt_0200d808
rt_0200d798:
    cmp r4, lr
rt_0200d79c:
    beq rt_0200d7f0
rt_0200d7a0:
    movs r3, r3, lsl #0xc
rt_0200d7a4:
    beq rt_0200d7d0
rt_0200d7a8:
    clz r5, r3
rt_0200d7ac:
    movs r3, r3, lsl r5
rt_0200d7b0:
    sub r4, r4, r5
rt_0200d7b4:
    add r5, r4, #0x1f
rt_0200d7b8:
    mov r3, r3, lsr #0xb
rt_0200d7bc:
    orr r3, r3, r2, lsr r5
rt_0200d7c0:
    rsb r5, r5, #0x20
rt_0200d7c4:
    mov r2, r2, lsl r5
rt_0200d7c8:
    mov r4, r4, lsl #1
rt_0200d7cc:
    b rt_0200d384
rt_0200d7d0:
    mvn r4, #0x13
rt_0200d7d4:
    clz r5, r2
rt_0200d7d8:
    movs r2, r2, lsl r5
rt_0200d7dc:
    sub r4, r4, r5
rt_0200d7e0:
    mov r3, r2, lsr #0xb
rt_0200d7e4:
    mov r2, r2, lsl #0x15
rt_0200d7e8:
    mov r4, r4, lsl #1
rt_0200d7ec:
    b rt_0200d384
rt_0200d7f0:
    orrs r5, r2, r3, lsl #12
rt_0200d7f4:
    bne rt_0200d864
rt_0200d7f8:
    mov r1, r12, lsl #0x1f
rt_0200d7fc:
    mov r0, #0
rt_0200d800:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d804:
    bx lr
rt_0200d808:
    mov r1, r12, lsl #0x1f
rt_0200d80c:
    orr r1, r1, lr, lsl #19
rt_0200d810:
    mov r0, #0
rt_0200d814:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d818:
    bx lr
rt_0200d81c:
    orrs r5, r2, r3, lsl #1
rt_0200d820:
    beq rt_0200d87c
rt_0200d824:
    bic r5, r3, #0x80000000
rt_0200d828:
    cmp r5, lr, lsl #19
rt_0200d82c:
    cmpeq r2, #0
rt_0200d830:
    bhi rt_0200d864
rt_0200d834:
    eor r1, r1, r3
rt_0200d838:
    and r1, r1, #0x80000000
rt_0200d83c:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d840:
    bx lr
rt_0200d844:
    tst r1, #0x80000
rt_0200d848:
    beq rt_0200d87c
rt_0200d84c:
    bic r5, r3, #0x80000000
rt_0200d850:
    cmp r5, lr, lsl #19
rt_0200d854:
    cmpeq r2, #0
rt_0200d858:
    bhi rt_0200d864
rt_0200d85c:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d860:
    bx lr
rt_0200d864:
    tst r3, #0x80000
rt_0200d868:
    beq rt_0200d87c
rt_0200d86c:
    mov r1, r3
rt_0200d870:
    mov r0, r2
rt_0200d874:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d878:
    bx lr
rt_0200d87c:
    orr r1, r1, #0x7f000000
rt_0200d880:
    orr r1, r1, #0xf80000
rt_0200d884:
    ldmia sp!, {r4, r5, r6, lr}
rt_0200d888:
    bx lr
rt_0200d88c:
    dcd 0x00000ffe // Literal/table data, not an instruction.
}
