#include <globaldefs.h>
extern "C" void func_ov023_021e76a8(void*);
extern "C" void ResetEachIndexedEntryResource(void*);
extern "C" void func_ov023_021e6b8c(void*);
// Release profile-screen components, including the optional UI manager.
// Original: arm9/ov012 @ 0x02185AB8; symbol: func_ov012_02185ab8; size: 0x38.
extern "C" void func_ov012_02185ab8(unsigned char* screen) {
    func_ov023_021e76a8(screen + 0xd28);
    if (screen[0x1371]) ResetEachIndexedEntryResource(screen + 0xac);
    func_ov023_021e6b8c(screen);
}
