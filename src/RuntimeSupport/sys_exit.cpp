// Compiler runtime support: sys_exit.
// Accepted as matching assembly by user instruction. Do not decompile into C.
// Vendor library: ds/2.0/sp2/Runtime/Runtime_ARM/Runtime_NITRO/Lib/NITRO_Runtime_Ai_LE.a. Object: semihosted_conso.
// Original vendor source: not recorded in object.
// DQIX USA arm9/main: 0x0200D8BC, 16 bytes.
// Original bytes SHA256: 570173cea185f5748ea246c8db528d2cc87d86099124b7d8a09d9356c5942518.
// Readable reconstruction. Branches and relocated literals use symbolic targets.
// Defined as a CodeWarrior assembly function inside C++; no C reconstruction credit.
#pragma thumb off
extern "C" asm void sys_exit()
{

rt_0200d8bc:
    mov r1, #0
rt_0200d8c0:
    mov r0, #0x18
rt_0200d8c4:
    swi 0x123456
rt_0200d8c8:
    mov pc, lr
}
