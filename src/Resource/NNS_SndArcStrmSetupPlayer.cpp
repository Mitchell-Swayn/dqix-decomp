#include <globaldefs.h>
struct Channel { unsigned char pad[0x124]; unsigned char count; unsigned char pad125; unsigned char ids[6]; void* buffer; unsigned bytes; unsigned char tail[0x40]; };
// Original data: arm9/main @ 0x2110a4c; symbol: data_02110a4c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1492 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" Channel NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant6[4];
extern "C" { unsigned char* NNS_SndArcGetStrmPlayerInfo(int); void* ResourceAllocator_AllocateTrackedAlignedBlock(void*, unsigned, void (*)(void*), Channel*, int); void ResourceJob_ReleaseMatchingHandleUnderMutexes(void*); void ResourceJob_RunCallbacksUnderMutexes(Channel*); }
// Original: arm9/main @ 0x020BEAEC; symbol: func_020beaec; size: 0xC8.
extern "C" ARM int NNS_SndArcStrmSetupPlayer(void* allocator) {
    int i=0;
    unsigned bytes;
    Channel* channel = NNSSndArcStrmInit_UnknownRoleZeroInitializedStorage_Variant6;
    do {
        unsigned char* config=NNS_SndArcGetStrmPlayerInfo(i);
        if(config) {
            channel->count=*config;
            int j=0;
            int count=*config;
            if(count>0) do { channel->ids[j]=(config+j)[1]; } while(++j<*config);
            if(allocator) {
                bytes=channel->count<<11;
                void* buffer=ResourceAllocator_AllocateTrackedAlignedBlock(allocator,bytes,ResourceJob_ReleaseMatchingHandleUnderMutexes,channel,0);
                if(!buffer) return 0;
                ResourceJob_RunCallbacksUnderMutexes(channel);
                channel->buffer=buffer; channel->bytes=bytes;
            }
        }
        channel++;
    } while(++i<4);
    return 1;
}
