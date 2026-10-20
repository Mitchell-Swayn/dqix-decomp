// SDK support (community reconstruction): CP_SaveContext.
// Pinned NitroSDK CP_SaveContext: see build/provenance-020cd594.json.
// Assembly coverage only; not C/C++ reconstruction credit.
struct CPContext;
// Original: arm9/main @ 0x020CD594; symbol: func_020cd594; size: 0x40.
extern "C" asm void CP_SaveContext(register CPContext *context) {
 ldr r1, =0x04000290
 stmfd sp!, {r4}
 ldmia r1, {r2-r4, r12}
 stmia r0!, {r2-r4, r12}
 ldrh r12, [r1, #-0x10]
 add r1, r1, #0x28
 ldmia r1, {r2-r3}
 stmia r0!, {r2-r3}
 and r12, r12, #3
 ldrh r2, [r1, #-8]
 strh r12, [r0]
 and r2, r2, #1
 strh r2, [r0, #2]
 ldmfd sp!, {r4}
 bx lr
}
