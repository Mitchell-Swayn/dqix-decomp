// Compiler runtime support: _u32_div_f.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Mathlib/lib/FP_fastI_v5t_LE.a. Object: _u32_div_f.o.
// Original vendor source: D:\Products\ARM\NITRO_Support_3_0_auto\output\ARM_EABI_Support\Mathlib\_u32_div_f.s.
// DQIX USA arm9/main: 0x0200D150, 484 bytes.
// Original bytes SHA256: 3b0403581ea03e86bdfc0cde00ea2ca13f522291aec399b93ecdf2fef57944eb.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _u32_div_f()
{

rt_0200d150:
    cmp r1, #0
rt_0200d154:
    bxeq lr
rt_0200d158:
data_0200d158:
    cmp r0, r1
rt_0200d15c:
    movlo r1, r0
rt_0200d160:
    movlo r0, #0
rt_0200d164:
    bxlo lr
rt_0200d168:
    mov r2, #0x1c
rt_0200d16c:
    mov r3, r0, lsr #4
rt_0200d170:
    cmp r1, r3, lsr #12
rt_0200d174:
    suble r2, r2, #0x10
rt_0200d178:
    movle r3, r3, lsr #0x10
rt_0200d17c:
    cmp r1, r3, lsr #4
rt_0200d180:
    suble r2, r2, #8
rt_0200d184:
    movle r3, r3, lsr #8
rt_0200d188:
    cmp r1, r3
rt_0200d18c:
    suble r2, r2, #4
rt_0200d190:
    movle r3, r3, lsr #4
rt_0200d194:
    mov r0, r0, lsl r2
rt_0200d198:
    rsb r1, r1, #0
rt_0200d19c:
    adds r0, r0, r0
rt_0200d1a0:
    add r2, r2, r2, lsl #1
rt_0200d1a4:
    add pc, pc, r2, lsl #2
rt_0200d1a8:
    mov r0, r0
rt_0200d1ac:
    adcs r3, r1, r3, lsl #1
rt_0200d1b0:
    sublo r3, r3, r1
rt_0200d1b4:
    adcs r0, r0, r0
rt_0200d1b8:
    adcs r3, r1, r3, lsl #1
rt_0200d1bc:
    sublo r3, r3, r1
rt_0200d1c0:
    adcs r0, r0, r0
rt_0200d1c4:
    adcs r3, r1, r3, lsl #1
rt_0200d1c8:
    sublo r3, r3, r1
rt_0200d1cc:
    adcs r0, r0, r0
rt_0200d1d0:
    adcs r3, r1, r3, lsl #1
rt_0200d1d4:
    sublo r3, r3, r1
rt_0200d1d8:
    adcs r0, r0, r0
rt_0200d1dc:
    adcs r3, r1, r3, lsl #1
rt_0200d1e0:
    sublo r3, r3, r1
rt_0200d1e4:
    adcs r0, r0, r0
rt_0200d1e8:
    adcs r3, r1, r3, lsl #1
rt_0200d1ec:
    sublo r3, r3, r1
rt_0200d1f0:
    adcs r0, r0, r0
rt_0200d1f4:
    adcs r3, r1, r3, lsl #1
rt_0200d1f8:
    sublo r3, r3, r1
rt_0200d1fc:
    adcs r0, r0, r0
rt_0200d200:
    adcs r3, r1, r3, lsl #1
rt_0200d204:
    sublo r3, r3, r1
rt_0200d208:
    adcs r0, r0, r0
rt_0200d20c:
    adcs r3, r1, r3, lsl #1
rt_0200d210:
    sublo r3, r3, r1
rt_0200d214:
    adcs r0, r0, r0
rt_0200d218:
    adcs r3, r1, r3, lsl #1
rt_0200d21c:
    sublo r3, r3, r1
rt_0200d220:
    adcs r0, r0, r0
rt_0200d224:
    adcs r3, r1, r3, lsl #1
rt_0200d228:
    sublo r3, r3, r1
rt_0200d22c:
    adcs r0, r0, r0
rt_0200d230:
    adcs r3, r1, r3, lsl #1
rt_0200d234:
    sublo r3, r3, r1
rt_0200d238:
    adcs r0, r0, r0
rt_0200d23c:
    adcs r3, r1, r3, lsl #1
rt_0200d240:
    sublo r3, r3, r1
rt_0200d244:
    adcs r0, r0, r0
rt_0200d248:
    adcs r3, r1, r3, lsl #1
rt_0200d24c:
    sublo r3, r3, r1
rt_0200d250:
    adcs r0, r0, r0
rt_0200d254:
    adcs r3, r1, r3, lsl #1
rt_0200d258:
    sublo r3, r3, r1
rt_0200d25c:
    adcs r0, r0, r0
rt_0200d260:
    adcs r3, r1, r3, lsl #1
rt_0200d264:
    sublo r3, r3, r1
rt_0200d268:
    adcs r0, r0, r0
rt_0200d26c:
    adcs r3, r1, r3, lsl #1
rt_0200d270:
    sublo r3, r3, r1
rt_0200d274:
    adcs r0, r0, r0
rt_0200d278:
    adcs r3, r1, r3, lsl #1
rt_0200d27c:
    sublo r3, r3, r1
rt_0200d280:
    adcs r0, r0, r0
rt_0200d284:
    adcs r3, r1, r3, lsl #1
rt_0200d288:
    sublo r3, r3, r1
rt_0200d28c:
    adcs r0, r0, r0
rt_0200d290:
    adcs r3, r1, r3, lsl #1
rt_0200d294:
    sublo r3, r3, r1
rt_0200d298:
    adcs r0, r0, r0
rt_0200d29c:
    adcs r3, r1, r3, lsl #1
rt_0200d2a0:
    sublo r3, r3, r1
rt_0200d2a4:
    adcs r0, r0, r0
rt_0200d2a8:
    adcs r3, r1, r3, lsl #1
rt_0200d2ac:
    sublo r3, r3, r1
rt_0200d2b0:
    adcs r0, r0, r0
rt_0200d2b4:
    adcs r3, r1, r3, lsl #1
rt_0200d2b8:
    sublo r3, r3, r1
rt_0200d2bc:
    adcs r0, r0, r0
rt_0200d2c0:
    adcs r3, r1, r3, lsl #1
rt_0200d2c4:
    sublo r3, r3, r1
rt_0200d2c8:
    adcs r0, r0, r0
rt_0200d2cc:
    adcs r3, r1, r3, lsl #1
rt_0200d2d0:
    sublo r3, r3, r1
rt_0200d2d4:
    adcs r0, r0, r0
rt_0200d2d8:
    adcs r3, r1, r3, lsl #1
rt_0200d2dc:
    sublo r3, r3, r1
rt_0200d2e0:
    adcs r0, r0, r0
rt_0200d2e4:
    adcs r3, r1, r3, lsl #1
rt_0200d2e8:
    sublo r3, r3, r1
rt_0200d2ec:
    adcs r0, r0, r0
rt_0200d2f0:
    adcs r3, r1, r3, lsl #1
rt_0200d2f4:
    sublo r3, r3, r1
rt_0200d2f8:
    adcs r0, r0, r0
rt_0200d2fc:
    adcs r3, r1, r3, lsl #1
rt_0200d300:
    sublo r3, r3, r1
rt_0200d304:
    adcs r0, r0, r0
rt_0200d308:
    adcs r3, r1, r3, lsl #1
rt_0200d30c:
    sublo r3, r3, r1
rt_0200d310:
    adcs r0, r0, r0
rt_0200d314:
    adcs r3, r1, r3, lsl #1
rt_0200d318:
    sublo r3, r3, r1
rt_0200d31c:
    adcs r0, r0, r0
rt_0200d320:
    adcs r3, r1, r3, lsl #1
rt_0200d324:
    sublo r3, r3, r1
rt_0200d328:
    adcs r0, r0, r0
rt_0200d32c:
    mov r1, r3
rt_0200d330:
    bx lr

// Shared compiler runtime tail following the named function.
    eor r1, r1, r3
    eor r3, r1, r3
    eor r1, r1, r3
    eor r0, r0, r2
    eor r2, r0, r2
    eor r0, r0, r2
}
