#include <globaldefs.h>
ARM
#include <System/Cache.h>
extern "C" char data_0210fd74[];
extern "C" unsigned data_0210fdbc[];
extern "C" void MIi_CpuClear32(unsigned,void*,unsigned);
extern "C" void SubmitOperationCodeTwelve(unsigned,unsigned,unsigned,unsigned);
// Original: arm9/main @ 0x020BD08C; symbol: func_020bd08c; size: 0x84.
extern "C" void ResourceTimer_ClearTwoBuffersAndSubmit() {
    unsigned* state=data_0210fdbc;
    if (!*(unsigned*)(data_0210fd74+0x48)) return;
    state[7]=0;
    MIi_CpuClear32(0,(void*)state[3],state[5]);
    MIi_CpuClear32(0,(void*)state[4],state[5]);
    CleanInvalidateCacheRange((void*)state[3],state[5]);
    CleanInvalidateCacheRange((void*)state[4],state[5]);
    int index=state[11];
    SubmitOperationCodeTwelve(state[9],state[10],index>=0?1u<<index:0,0);
}
