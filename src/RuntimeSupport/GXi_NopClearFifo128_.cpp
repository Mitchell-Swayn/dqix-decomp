// SDK support (community reconstruction): GXi_NopClearFifo128_.
// SDK support (community reconstruction): NitroSDK GXi_NopClearFifo128_.
// Original: arm9/main @ 0x020C56DC; symbol: func_020c56dc; size: 0x94.
// Reference: pret/pokediamond@b623abef1b4dfe204ca50aab42447ac00c134290 arm9/lib/NitroSDK/src/GX_g3x.c
// Emits128 zero words (packed NOP commands) to the fixed GX FIFO register block.
#pragma thumb off
extern "C" asm void GXi_NopClearFifo128_(void* fifo){
    mov r1, #0x0
    mov r2, #0x0
    mov r3, #0x0
    mov r12, #0x0
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    stmia r0, {r1-r3,r12}
    bx lr
}
