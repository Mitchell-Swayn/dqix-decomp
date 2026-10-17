#include <globaldefs.h>
ARM
extern "C" int ReadSharedSignedByteAtOffset22(void);
extern "C" int func_ov031_02227840(void);
extern "C" void ClearGlobalControlByte18(void);
extern "C" void SetMainLoopCallback(void*);
extern "C" void func_ov031_0222a4f0(void);
// Original: arm9/ov031 @ 0x0222A4BC; symbol: func_ov031_0222a4bc; size: 0x34.
extern "C" void func_ov031_0222a4bc(void) {
    if (ReadSharedSignedByteAtOffset22() == -2) return;
    if (!func_ov031_02227840()) return;
    ClearGlobalControlByte18();
    SetMainLoopCallback((void*)func_ov031_0222a4f0);
}
