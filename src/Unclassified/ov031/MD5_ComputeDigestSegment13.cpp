#include <globaldefs.h>
ARM
extern "C" void InitializeMD5StateConstants(unsigned*);
extern "C" void func_020c0368(void*, const void*, unsigned);
extern "C" void func_020c0430(void*, void*);
extern "C" void MI_CpuCopy8(const void*, void*, unsigned);
// Original: arm9/ov031 @ 0x022158FC; symbol: func_ov031_022158fc; size: 0x4C.
extern "C" void MD5_ComputeDigestSegment13(const void* input, void* output) {
    unsigned char workspace[0x6c];
    InitializeMD5StateConstants((unsigned*)(workspace + 0x14));
    func_020c0368(workspace + 0x14, input, 0x18);
    func_020c0430(workspace, workspace + 0x14);
    MI_CpuCopy8(workspace + 3, output, 0xd);
}
