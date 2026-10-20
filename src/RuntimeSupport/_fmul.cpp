// Compiler runtime support: _f_mul, _fmul.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _f_mul.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_f_mul.s.
// DQIX USA arm9/main: 0x0200C7D4, 480 bytes.
// Original bytes SHA256: 21410393c8ab1edc30019dd39efd54e8e35b8ca31c39c92fbd114e2211af8bed.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _fmul()
{

rt_0200c7d4:
    eor r2, r0, r1
rt_0200c7d8:
    and r2, r2, #0x80000000
rt_0200c7dc:
    mov r12, #0xff
rt_0200c7e0:
    ands r3, r12, r0, lsr #23
rt_0200c7e4:
    mov r0, r0, lsl #8
rt_0200c7e8:
    cmpne r3, #0xff
rt_0200c7ec:
    beq rt_0200c850
rt_0200c7f0:
    orr r0, r0, #0x80000000
rt_0200c7f4:
    ands r12, r12, r1, lsr #23
rt_0200c7f8:
    mov r1, r1, lsl #8
rt_0200c7fc:
    cmpne r12, #0xff
rt_0200c800:
    beq rt_0200c890
rt_0200c804:
    orr r1, r1, #0x80000000
rt_0200c808:
    add r12, r3, r12
rt_0200c80c:
    umull r1, r3, r0, r1
rt_0200c810:
    movs r0, r3
rt_0200c814:
    addpl r0, r0, r0
rt_0200c818:
    subpl r12, r12, #1
rt_0200c81c:
    subs r12, r12, #0x7f
rt_0200c820:
    bmi rt_0200c91c
rt_0200c824:
    cmp r12, #0xfe
rt_0200c828:
    bge rt_0200c988
rt_0200c82c:
    ands r3, r0, #0xff
rt_0200c830:
    orr r0, r2, r0, lsr #8
rt_0200c834:
    add r0, r0, r12, lsl #23
rt_0200c838:
    tst r3, #0x80
rt_0200c83c:
    bxeq lr
rt_0200c840:
    orrs r1, r1, r3, lsl #25
rt_0200c844:
    andeqs r3, r0, #1
rt_0200c848:
    addne r0, r0, #1
rt_0200c84c:
    bx lr
rt_0200c850:
    cmp r3, #0
rt_0200c854:
    beq rt_0200c8a4
rt_0200c858:
    movs r0, r0, lsl #1
rt_0200c85c:
    bne rt_0200c978
rt_0200c860:
    mov r12, r1, lsr #0x17
rt_0200c864:
    mov r1, r1, lsl #9
rt_0200c868:
    ands r12, r12, #0xff
rt_0200c86c:
    beq rt_0200c884
rt_0200c870:
    cmp r12, #0xff
rt_0200c874:
    blt rt_0200c96c
rt_0200c878:
    cmp r1, #0
rt_0200c87c:
    beq rt_0200c96c
rt_0200c880:
    b rt_0200c978
rt_0200c884:
    cmp r1, #0
rt_0200c888:
    beq rt_0200c980
rt_0200c88c:
    b rt_0200c96c
rt_0200c890:
    cmp r12, #0
rt_0200c894:
    beq rt_0200c900
rt_0200c898:
    movs r1, r1, lsl #1
rt_0200c89c:
    bne rt_0200c978
rt_0200c8a0:
    b rt_0200c96c
rt_0200c8a4:
    movs r0, r0, lsl #1
rt_0200c8a8:
    beq rt_0200c8dc
rt_0200c8ac:
    mov r0, r0, lsr #1
rt_0200c8b0:
    clz r3, r0
rt_0200c8b4:
    movs r0, r0, lsl r3
rt_0200c8b8:
    rsb r3, r3, #1
rt_0200c8bc:
    mov r12, r1, lsr #0x17
rt_0200c8c0:
    mov r1, r1, lsl #8
rt_0200c8c4:
    ands r12, r12, #0xff
rt_0200c8c8:
    beq rt_0200c900
rt_0200c8cc:
    cmp r12, #0xff
rt_0200c8d0:
    beq rt_0200c898
rt_0200c8d4:
    orr r1, r1, #0x80000000
rt_0200c8d8:
    b rt_0200c808
rt_0200c8dc:
    mov r12, r1, lsr #0x17
rt_0200c8e0:
    mov r1, r1, lsl #9
rt_0200c8e4:
    ands r12, r12, #0xff
rt_0200c8e8:
    beq rt_0200c9ac
rt_0200c8ec:
    cmp r12, #0xff
rt_0200c8f0:
    blt rt_0200c9ac
rt_0200c8f4:
    cmp r1, #0
rt_0200c8f8:
    beq rt_0200c980
rt_0200c8fc:
    b rt_0200c978
rt_0200c900:
    movs r1, r1, lsl #1
rt_0200c904:
    beq rt_0200c9ac
rt_0200c908:
    mov r1, r1, lsr #1
rt_0200c90c:
    clz r12, r1
rt_0200c910:
    movs r1, r1, lsl r12
rt_0200c914:
    rsb r12, r12, #1
rt_0200c918:
    b rt_0200c808
rt_0200c91c:
    cmn r12, #0x18
rt_0200c920:
    beq rt_0200c964
rt_0200c924:
    bmi rt_0200c9a4
rt_0200c928:
    cmp r1, #0
rt_0200c92c:
    orrne r0, r0, #1
rt_0200c930:
    mov r3, r0
rt_0200c934:
    mov r0, r0, lsr #8
rt_0200c938:
    rsb r12, r12, #0
rt_0200c93c:
    orr r0, r2, r0, lsr r12
rt_0200c940:
    rsb r12, r12, #0x18
rt_0200c944:
    movs r1, r3, lsl r12
rt_0200c948:
    bxeq lr
rt_0200c94c:
    tst r1, #0x80000000
rt_0200c950:
    bxeq lr
rt_0200c954:
    movs r1, r1, lsl #1
rt_0200c958:
    andeqs r1, r0, #1
rt_0200c95c:
    addne r0, r0, #1
rt_0200c960:
    bx lr
rt_0200c964:
    mov r0, r0, lsl #1
rt_0200c968:
    b rt_0200c994
rt_0200c96c:
    mov r0, #0xff000000
rt_0200c970:
    orr r0, r2, r0, lsr #1
rt_0200c974:
    bx lr
rt_0200c978:
    mvn r0, #0x80000000
rt_0200c97c:
    bx lr
rt_0200c980:
    mvn r0, #0x80000000
rt_0200c984:
    bx lr
rt_0200c988:
    mov r0, #0xff000000
rt_0200c98c:
    orr r0, r2, r0, lsr #1
rt_0200c990:
    bx lr
rt_0200c994:
    movs r1, r0
rt_0200c998:
    mov r0, r2
rt_0200c99c:
    addne r0, r0, #1
rt_0200c9a0:
    bx lr
rt_0200c9a4:
    mov r0, r2
rt_0200c9a8:
    bx lr
rt_0200c9ac:
    mov r0, r2
rt_0200c9b0:
    bx lr
}
