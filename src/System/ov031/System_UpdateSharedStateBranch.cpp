#include <globaldefs.h>
ARM
extern "C" void System_ResolveGlobalGroupEntry(unsigned);
extern "C" void* Unclassified_InvokeHelperWithZeroFifthArgument(unsigned, void (*)(), unsigned, unsigned);
extern "C" void func_ov031_0222c71c();
extern "C" unsigned char data_ov031_02290c8c[];
// Original: arm9/ov031 @ 0x0222CA64; symbol: func_ov031_0222ca64; size: 0x74.
extern "C" void System_UpdateSharedStateBranch(void) {
    if (*(unsigned short*)(data_ov031_02290c8c + 2) == 0) {
        if ((*(unsigned char**)(data_ov031_02290c8c + 4))[0x59]) return;
        System_ResolveGlobalGroupEntry(9);
        (*(unsigned char**)(data_ov031_02290c8c + 4))[0x59] = 1;
        return;
    }
    System_ResolveGlobalGroupEntry(0x13);
    (*(void**)(*(unsigned char**)(data_ov031_02290c8c + 4) + 0x38)) = Unclassified_InvokeHelperWithZeroFifthArgument(0, func_ov031_0222c71c, 0, 0x78);
}
