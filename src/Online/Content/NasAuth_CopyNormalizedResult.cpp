#include <globaldefs.h>
#include <System/Memory.h>
ARM
// Original data: arm9/ov031 @ 0x224e5e8; symbol: data_ov031_0224e5e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NasAuthDestroySession_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02216B00; symbol: func_ov031_02216b00; size: 0x90.
extern "C" void NasAuth_CopyNormalizedResult(unsigned char* output) {
if(!*(void**)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage+8))VectorizedMemset(output,0,0x1c4);
MI_CpuCopy8(*(unsigned char**)(NasAuthDestroySession_UnknownRoleZeroInitializedStorage+8)+0x1008,output,0x1c4);
int code=*(int*)output;
if(code<20000 || code>=30000)*(int*)output=0x5206;
if(*(int*)output>=20100)*(int*)output=-*(int*)output;
}
