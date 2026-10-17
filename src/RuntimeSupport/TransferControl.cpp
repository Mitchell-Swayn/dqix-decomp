// Compiler runtime support: _Z17__TransferControlP12ThrowContextP13ExceptionInfoPc.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Runtime/Runtime_ARM/Runtime_NITRO/Lib/NITRO_Runtime_Ai_LE.a. Object: exceptionhandler.
// Original vendor source: not recorded in object.
// DQIX USA arm9/main: 0x0200F2EC, 48 bytes.
// Original bytes SHA256: e7ff02e1abff015edc15a122901399abf6a9ccd24e65ba557c6f6d4444cd9f96.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void _Z17__TransferControlP12ThrowContextP13ExceptionInfoPc()
{

rt_0200f2ec:
    ldr r4, [r0, #0x2c]
rt_0200f2f0:
    ldr r5, [r0, #0x30]
rt_0200f2f4:
    ldr r6, [r0, #0x34]
rt_0200f2f8:
    ldr r7, [r0, #0x38]
rt_0200f2fc:
    ldr r8, [r0, #0x3c]
rt_0200f300:
    ldr r9, [r0, #0x40]
rt_0200f304:
    ldr r10, [r0, #0x44]
rt_0200f308:
    ldr r11, [r0, #0x48]
rt_0200f30c:
    ldr sp, [r0, #0x5c]
rt_0200f310:
    ldr r12, [r0, #0x64]
rt_0200f314:
    sub sp, sp, r12
rt_0200f318:
    bx r2
}
