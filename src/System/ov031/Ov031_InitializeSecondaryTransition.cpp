#include <globaldefs.h>
extern "C" unsigned char data_ov031_02290cc0[];
extern "C" void* Memory_AllocateZeroedBlock(unsigned, unsigned);
extern "C" void func_ov031_02232568();
extern "C" void System_CreateCopyAndFinalizeResource(unsigned);
extern "C" void func_ov031_0222336c(unsigned, int, unsigned);
extern "C" void func_ov031_02223518(unsigned);
extern "C" void func_ov031_02232678();
extern "C" void func_ov031_02232ce8();
extern "C" void func_ov031_02232780();
extern "C" void SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02232508; symbol: func_ov031_02232508; size: 0x60.
extern "C" ARM void Ov031_InitializeSecondaryTransition() {
    void* object = Memory_AllocateZeroedBlock(0x20, 4);
    *(void**)(data_ov031_02290cc0 + 4) = object;
    *((unsigned char*)object + 0x1d) = 0;
    func_ov031_02232568();
    System_CreateCopyAndFinalizeResource(1);
    func_ov031_0222336c(0x2f, -1, 0);
    func_ov031_02223518(0);
    func_ov031_02232678();
    func_ov031_02232ce8();
    SetMainLoopCallback(func_ov031_02232780);
}
