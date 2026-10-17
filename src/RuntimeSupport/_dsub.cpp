// Compiler runtime support: _d_sub, _dsub.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _d_sub.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_d_sub.s.
// DQIX USA arm9/main: 0x0200B608, 948 bytes.
// Original bytes SHA256: 839edf66641e5f704ce7925accf57c0ef6375aeccca1666166300a06874d7741.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
// Shared tails have no original relocation. The inline assembler accepts only
// bare branch labels, so encode their ARM branch displacement symbolically.
#define RUNTIME_BRANCH(condition, displacement) (((condition) << 28) | 0x0a000000u | (((((displacement) - 8) / 4)) & 0x00ffffffu))
extern "C" asm void _dsub()
{

rt_0200b608:
    stmdb sp!, {r4, lr}
rt_0200b60c:
    eors r12, r1, r3
rt_0200b610:
    eormi r3, r3, #0x80000000
rt_0200b614:
    dcd RUNTIME_BRANCH(4, -2780) // Shared runtime tail target: _dadd + 16
rt_0200b618:
    subs r12, r0, r2
rt_0200b61c:
    sbcs lr, r1, r3
rt_0200b620:
    bhs rt_0200b638
rt_0200b624:
    eor lr, lr, #0x80000000
rt_0200b628:
    adds r2, r2, r12
rt_0200b62c:
    adc r3, r3, lr
rt_0200b630:
    subs r0, r0, r12
rt_0200b634:
    sbc r1, r1, lr
rt_0200b638:
    mov lr, #0x80000000
rt_0200b63c:
    mov r12, r1, lsr #0x14
rt_0200b640:
    orr r1, lr, r1, lsl #11
rt_0200b644:
    orr r1, r1, r0, lsr #21
rt_0200b648:
    mov r0, r0, lsl #0xb
rt_0200b64c:
    movs r4, r12, lsl #0x15
rt_0200b650:
    cmnne r4, #0x200000
rt_0200b654:
    beq rt_0200b83c
rt_0200b658:
    mov r4, r3, lsr #0x14
rt_0200b65c:
    orr r3, lr, r3, lsl #11
rt_0200b660:
    orr r3, r3, r2, lsr #21
rt_0200b664:
    mov r2, r2, lsl #0xb
rt_0200b668:
    movs lr, r4, lsl #0x15
rt_0200b66c:
    beq rt_0200b884
rt_0200b670:
    subs r4, r12, r4
rt_0200b674:
    beq rt_0200b718
rt_0200b678:
    cmp r4, #0x20
rt_0200b67c:
    ble rt_0200b6ac
rt_0200b680:
    cmp r4, #0x38
rt_0200b684:
    movge r4, #0x3f
rt_0200b688:
    sub r4, r4, #0x20
rt_0200b68c:
    rsb lr, r4, #0x20
rt_0200b690:
    orrs lr, r2, r3, lsl lr
rt_0200b694:
    mov r2, r3, lsr r4
rt_0200b698:
    orrne r2, r2, #1
rt_0200b69c:
    subs r0, r0, r2
rt_0200b6a0:
    sbcs r1, r1, #0
rt_0200b6a4:
    bmi rt_0200b6d4
rt_0200b6a8:
    b rt_0200b7c4
rt_0200b6ac:
    rsb lr, r4, #0x20
rt_0200b6b0:
    movs lr, r2, lsl lr
rt_0200b6b4:
    rsb lr, r4, #0x20
rt_0200b6b8:
    mov r2, r2, lsr r4
rt_0200b6bc:
    orr r2, r2, r3, lsl lr
rt_0200b6c0:
    mov r3, r3, lsr r4
rt_0200b6c4:
    orrne r2, r2, #1
rt_0200b6c8:
    subs r0, r0, r2
rt_0200b6cc:
    sbcs r1, r1, r3
rt_0200b6d0:
    bpl rt_0200b7c4
rt_0200b6d4:
    movs r2, r0, lsl #0x15
rt_0200b6d8:
    mov r0, r0, lsr #0xb
rt_0200b6dc:
    orr r0, r0, r1, lsl #21
rt_0200b6e0:
    add r1, r1, r1
rt_0200b6e4:
    mov r1, r1, lsr #0xc
rt_0200b6e8:
    orr r1, r1, r12, lsl #20
rt_0200b6ec:
    tst r2, #0x80000000
rt_0200b6f0:
    ldmeqia sp!, {r4, lr}
rt_0200b6f4:
    bxeq lr
rt_0200b6f8:
    movs r2, r2, lsl #1
rt_0200b6fc:
    andeqs r2, r0, #1
rt_0200b700:
    ldmeqia sp!, {r4, lr}
rt_0200b704:
    bxeq lr
rt_0200b708:
    adds r0, r0, #1
rt_0200b70c:
    adc r1, r1, #0
rt_0200b710:
    ldmia sp!, {r4, lr}
rt_0200b714:
    bx lr
rt_0200b718:
    subs r0, r0, r2
rt_0200b71c:
    sbc r1, r1, r3
rt_0200b720:
    orrs lr, r1, r0
rt_0200b724:
    beq rt_0200b9a8
rt_0200b728:
    mov lr, r12, lsl #0x14
rt_0200b72c:
    and lr, lr, #0x80000000
rt_0200b730:
    bic r12, r12, #0x800
rt_0200b734:
    cmp r1, #0
rt_0200b738:
    bmi rt_0200b7a0
rt_0200b73c:
    bne rt_0200b750
rt_0200b740:
    sub r12, r12, #0x20
rt_0200b744:
    movs r1, r0
rt_0200b748:
    mov r0, #0
rt_0200b74c:
    bmi rt_0200b76c
rt_0200b750:
    clz r4, r1
rt_0200b754:
    movs r1, r1, lsl r4
rt_0200b758:
    rsb r4, r4, #0x20
rt_0200b75c:
    orr r1, r1, r0, lsr r4
rt_0200b760:
    rsb r4, r4, #0x20
rt_0200b764:
    mov r0, r0, lsl r4
rt_0200b768:
    sub r12, r12, r4
rt_0200b76c:
    cmp r12, #0
rt_0200b770:
    bgt rt_0200b7a8
rt_0200b774:
    rsb r12, r12, #0xc
rt_0200b778:
    cmp r12, #0x20
rt_0200b77c:
    movge r0, r1
rt_0200b780:
    movge r1, #0
rt_0200b784:
    subge r12, r12, #0x20
rt_0200b788:
    rsb r4, r12, #0x20
rt_0200b78c:
    mov r0, r0, lsr r12
rt_0200b790:
    orr r0, r0, r1, lsl r4
rt_0200b794:
    orr r1, lr, r1, lsr r12
rt_0200b798:
    ldmia sp!, {r4, lr}
rt_0200b79c:
    bx lr
rt_0200b7a0:
    cmp r1, #0
rt_0200b7a4:
    subges r12, r12, #1
rt_0200b7a8:
    mov r0, r0, lsr #0xb
rt_0200b7ac:
    orr r0, r0, r1, lsl #21
rt_0200b7b0:
    add r1, r1, r1
rt_0200b7b4:
    orr r1, lr, r1, lsr #12
rt_0200b7b8:
    orr r1, r1, r12, lsl #20
rt_0200b7bc:
    ldmia sp!, {r4, lr}
rt_0200b7c0:
    bx lr
rt_0200b7c4:
    mov lr, r12, lsl #0x14
rt_0200b7c8:
    and lr, lr, #0x80000000
rt_0200b7cc:
    bic r12, r12, #0x800
rt_0200b7d0:
    cmp r1, #0
rt_0200b7d4:
    bne rt_0200b7e8
rt_0200b7d8:
    sub r12, r12, #0x20
rt_0200b7dc:
    movs r1, r0
rt_0200b7e0:
    mov r0, #0
rt_0200b7e4:
    bmi rt_0200b804
rt_0200b7e8:
    clz r4, r1
rt_0200b7ec:
    movs r1, r1, lsl r4
rt_0200b7f0:
    rsb r4, r4, #0x20
rt_0200b7f4:
    orr r1, r1, r0, lsr r4
rt_0200b7f8:
    rsb r4, r4, #0x20
rt_0200b7fc:
    mov r0, r0, lsl r4
rt_0200b800:
    sub r12, r12, r4
rt_0200b804:
    cmp r12, #0
rt_0200b808:
    orrgt r12, r12, lr, lsr #20
rt_0200b80c:
    bgt rt_0200b6d4
rt_0200b810:
    rsb r12, r12, #0xc
rt_0200b814:
    cmp r12, #0x20
rt_0200b818:
    movge r0, r1
rt_0200b81c:
    movge r1, #0
rt_0200b820:
    subge r12, r12, #0x20
rt_0200b824:
    rsb r4, r12, #0x20
rt_0200b828:
    mov r0, r0, lsr r12
rt_0200b82c:
    orr r0, r0, r1, lsl r4
rt_0200b830:
    orr r1, lr, r1, lsr r12
rt_0200b834:
    ldmia sp!, {r4, lr}
rt_0200b838:
    bx lr
rt_0200b83c:
    cmp r12, #0x800
rt_0200b840:
    movge lr, #0x80000000
rt_0200b844:
    movlt lr, #0
rt_0200b848:
    bics r12, r12, #0x800
rt_0200b84c:
    beq rt_0200b8a8
rt_0200b850:
    orrs r4, r0, r1, lsl #1
rt_0200b854:
    bne rt_0200b984
rt_0200b858:
    mov r4, r3, lsr #0x14
rt_0200b85c:
    mov r3, r3, lsl #0xb
rt_0200b860:
    orr r3, r3, r2, lsr #21
rt_0200b864:
    mov r2, r2, lsl #0xb
rt_0200b868:
    movs r4, r4, lsl #0x15
rt_0200b86c:
    beq rt_0200b970
rt_0200b870:
    cmn r4, #0x200000
rt_0200b874:
    bne rt_0200b970
rt_0200b878:
    orrs r4, r2, r3, lsl #1
rt_0200b87c:
    beq rt_0200b998
rt_0200b880:
    b rt_0200b984
rt_0200b884:
    cmp r4, #0x800
rt_0200b888:
    movge lr, #0x80000000
rt_0200b88c:
    movlt lr, #0
rt_0200b890:
    bic r12, r12, #0x800
rt_0200b894:
    bics r4, r4, #0x800
rt_0200b898:
    beq rt_0200b920
rt_0200b89c:
    orrs r4, r2, r3, lsl #1
rt_0200b8a0:
    bne rt_0200b984
rt_0200b8a4:
    b rt_0200b970
rt_0200b8a8:
    orrs r4, r0, r1, lsl #1
rt_0200b8ac:
    beq rt_0200b8e8
rt_0200b8b0:
    mov r12, #1
rt_0200b8b4:
    bic r1, r1, #0x80000000
rt_0200b8b8:
    mov r4, r3, lsr #0x14
rt_0200b8bc:
    mov r3, r3, lsl #0xb
rt_0200b8c0:
    orr r3, r3, r2, lsr #21
rt_0200b8c4:
    mov r2, r2, lsl #0xb
rt_0200b8c8:
    movs r4, r4, lsl #0x15
rt_0200b8cc:
    cmnne r4, #0x200000
rt_0200b8d0:
    mov r4, r4, lsr #0x15
rt_0200b8d4:
    orr r4, r4, lr, lsr #20
rt_0200b8d8:
    beq rt_0200b884
rt_0200b8dc:
    orr r3, r3, #0x80000000
rt_0200b8e0:
    orr r12, r12, lr, lsr #20
rt_0200b8e4:
    b rt_0200b670
rt_0200b8e8:
    mov r12, r3, lsr #0x14
rt_0200b8ec:
    mov r1, r3, lsl #0xb
rt_0200b8f0:
    orr r1, r1, r2, lsr #21
rt_0200b8f4:
    mov r0, r2, lsl #0xb
rt_0200b8f8:
    movs r4, r12, lsl #0x15
rt_0200b8fc:
    beq rt_0200b914
rt_0200b900:
    cmn r4, #0x200000
rt_0200b904:
    bne rt_0200b93c
rt_0200b908:
    orrs r4, r0, r1, lsl #1
rt_0200b90c:
    bne rt_0200b988
rt_0200b910:
    b rt_0200b970
rt_0200b914:
    orrs r4, r0, r1, lsl #1
rt_0200b918:
    beq rt_0200b9a8
rt_0200b91c:
    b rt_0200b93c
rt_0200b920:
    orrs r4, r2, r3, lsl #1
rt_0200b924:
    beq rt_0200b94c
rt_0200b928:
    mov r4, #1
rt_0200b92c:
    bic r3, r3, #0x80000000
rt_0200b930:
    orr r12, r12, lr, lsr #20
rt_0200b934:
    orr r4, r4, lr, lsr #20
rt_0200b938:
    b rt_0200b670
rt_0200b93c:
    mov r1, r3
rt_0200b940:
    mov r0, r2
rt_0200b944:
    ldmia sp!, {r4, lr}
rt_0200b948:
    bx lr
rt_0200b94c:
    cmp r1, #0
rt_0200b950:
    subges r12, r12, #1
rt_0200b954:
    mov r0, r0, lsr #0xb
rt_0200b958:
    orr r0, r0, r1, lsl #21
rt_0200b95c:
    add r1, r1, r1
rt_0200b960:
    orr r1, lr, r1, lsr #12
rt_0200b964:
    orr r1, r1, r12, lsl #20
rt_0200b968:
    ldmia sp!, {r4, lr}
rt_0200b96c:
    bx lr
rt_0200b970:
    ldr r1, [pc, #64] // Literal at 0x0200b9b8
rt_0200b974:
    orr r1, lr, r1
rt_0200b978:
    mov r0, #0
rt_0200b97c:
    ldmia sp!, {r4, lr}
rt_0200b980:
    bx lr
rt_0200b984:
    mov r1, r3
rt_0200b988:
    mvn r0, #0
rt_0200b98c:
    bic r1, r0, #0x80000000
rt_0200b990:
    ldmia sp!, {r4, lr}
rt_0200b994:
    bx lr
rt_0200b998:
    mvn r0, #0
rt_0200b99c:
    bic r1, r0, #0x80000000
rt_0200b9a0:
    ldmia sp!, {r4, lr}
rt_0200b9a4:
    bx lr
rt_0200b9a8:
    mov r1, #0
rt_0200b9ac:
    mov r0, #0
rt_0200b9b0:
    ldmia sp!, {r4, lr}
rt_0200b9b4:
    bx lr
rt_0200b9b8:
    dcd 0x7ff00000 // Literal/table data, not an instruction.
}
