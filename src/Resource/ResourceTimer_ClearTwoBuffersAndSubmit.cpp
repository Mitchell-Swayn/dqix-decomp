#include <globaldefs.h>
ARM
#include <System/Cache.h>
// Original data: arm9/main @ 0x210fd74; symbol: data_0210fd74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" char NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x210fdbc; symbol: data_0210fdbc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1460 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void MIi_CpuClear32(unsigned,void*,unsigned);
extern "C" void SoundCommand_SubmitOpcodeTwelve(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020BD08C; symbol: func_020bd08c; size: 0x84.
extern "C" void ResourceTimer_ClearTwoBuffersAndSubmit() {
    unsigned* state=NNSiSndCaptureStop_UnknownRoleZeroInitializedStorage_Variant2;
    if (!*(unsigned*)(NNSiSndCaptureInit_UnknownRoleZeroInitializedStorage+0x48)) return;
    state[7]=0;
    MIi_CpuClear32(0,(void*)state[3],state[5]);
    MIi_CpuClear32(0,(void*)state[4],state[5]);
    CleanInvalidateCacheRange((void*)state[3],state[5]);
    CleanInvalidateCacheRange((void*)state[4],state[5]);
    int index=state[11];
    SoundCommand_SubmitOpcodeTwelve(state[9],state[10],index>=0?1u<<index:0,0);
}
