#include <globaldefs.h>
ARM
extern "C" void MD5_InitializeState(unsigned*);
extern "C" void MD5_AppendBytesAndProcessCompleteBlocks(void*, const void*, unsigned);
extern "C" void MD5_FinalizeAndClearState(void*, void*);
extern "C" void MI_CpuCopy8(const void*, void*, unsigned);
// Original: arm9/ov031 @ 0x022158FC; symbol: func_ov031_022158fc; size: 0x4C.
extern "C" void MD5_ComputeDigestSegment13(const void* input, void* output) {
    unsigned char workspace[0x6c];
    MD5_InitializeState((unsigned*)(workspace + 0x14));
    MD5_AppendBytesAndProcessCompleteBlocks(workspace + 0x14, input, 0x18);
    MD5_FinalizeAndClearState(workspace, workspace + 0x14);
    MI_CpuCopy8(workspace + 3, output, 0xd);
}
