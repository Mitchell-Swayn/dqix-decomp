// SDK support (community reconstruction): VectorizedMemset, equivalent to NITRO SDK libmi MI_CpuFill8(dst, u8 data, size).
// Hand-written assembly, accepted by user instruction. NO C/C++ RECONSTRUCTION CREDIT. Not compiler runtime.
// DQIX USA arm9/main: 0x020CA594, 188 bytes, function_id arm9/main:020ca594.
// Original bytes SHA256: f5be979a555fb24f4afd7c39b0f4ab0fd7a874d38c37f8c8a3617d03f11c7aa9.
// Evidence origin: community reconstruction, NOT a vendor library/object/package match. Sources (pinned):
//   pret/pokediamond @ ed142f69171f575e9359e113cd18f315cb0fcdd3
//     arm9/lib/NitroSDK/src/MI_memory.c (asm void MI_CpuFill8; verbatim source is 37 instructions, original has 47)
//   pret/pokeheartgold @ 14c48938174ec92563afc6d03de5fa162f4cfdce
//     lib/NitroSDK/asm/mi_memory.s (MI_CpuFill8, conditional returns expanded; 47/47 words identical)
//   Hashes and the word-for-word comparison: build/provenance/manifest.json.
// Expansion: the original encodes each conditional return as "b<cc> L; b M; L: bx lr; M:" and the
// conditional halfword store as "b<ne> L; b M; L: strh; M:". The pinned mwccarm/mwasmarm emit the
// predicated forms (bxeq / strneh) for those mnemonics, so the expansions are written explicitly.
// The toolchain that produced the expansion is unknown. Labels are symbolic; all instructions are ordinary mnemonics.
#pragma thumb off
extern "C" asm void VectorizedMemset(register void* dst, register int value, register unsigned int length)
{
    cmp r2, #0
    beq exit_empty
    b skip_exit_empty
exit_empty:
    bx lr
skip_exit_empty:
    tst r0, #1
    beq aligned_16
    ldrh ip, [r0, #-1]
    and ip, ip, #0xff
    orr r3, ip, r1, lsl #8
    strh r3, [r0, #-1]
    add r0, r0, #1
    subs r2, r2, #1
    beq exit_after_byte
    b aligned_16
exit_after_byte:
    bx lr
aligned_16:
    cmp r2, #2
    blo tail_byte
    orr r1, r1, r1, lsl #8
    tst r0, #2
    beq aligned_32
    strh r1, [r0], #2
    subs r2, r2, #2
    beq exit_after_half
    b aligned_32
exit_after_half:
    bx lr
aligned_32:
    orr r1, r1, r1, lsl #16
    bics r3, r2, #3
    beq tail_half
    sub r2, r2, r3
    add ip, r3, r0
word_loop:
    str r1, [r0], #4
    cmp r0, ip
    blo word_loop
tail_half:
    tst r2, #2
    bne store_half
    b tail_byte
store_half:
    strh r1, [r0], #2
tail_byte:
    tst r2, #1
    beq exit_done
    b store_byte
exit_done:
    bx lr
store_byte:
    ldrh r3, [r0]
    and r3, r3, #0xff00
    and r1, r1, #0xff
    orr r1, r1, r3
    strh r1, [r0]
    bx lr
}
