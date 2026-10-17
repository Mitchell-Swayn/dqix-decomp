#include <globaldefs.h>
extern "C" unsigned ReadSelectedContextByte9(int);
extern "C" void func_ov031_0223c078(unsigned, unsigned, unsigned, unsigned);
extern "C" void func_ov031_02229bc8();
extern "C" void SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x02229B7C; symbol: func_ov031_02229b7c; size: 0x4C.
extern "C" ARM void Ov031_ConfigureThirdDisplayContext() {
    if (ReadSelectedContextByte9(1)) return;
    func_ov031_0223c078(3, 1, 0x3f, 0x40);
    func_ov031_0223c078(3, 0, 0x3f, 0x40);
    SetMainLoopCallback(func_ov031_02229bc8);
}
