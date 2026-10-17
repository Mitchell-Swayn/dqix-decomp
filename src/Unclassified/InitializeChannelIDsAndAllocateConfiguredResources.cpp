#include <globaldefs.h>
struct Channel { unsigned char pad[0x124]; unsigned char count; unsigned char pad125; unsigned char ids[6]; void* buffer; unsigned bytes; unsigned char tail[0x40]; };
extern "C" Channel data_02110a4c[4];
extern "C" { unsigned char* GetBoundedRelocatedBlobIndexEntryFromHeader20(int); void* ResourceAllocator_AllocateTrackedAlignedBlock(void*, unsigned, void (*)(void*), Channel*, int); void ResourceJob_ReleaseMatchingHandleUnderMutexes(void*); void ResourceJob_RunCallbacksUnderMutexes(Channel*); }
// Original: arm9/main @ 0x020BEAEC; symbol: func_020beaec; size: 0xC8.
extern "C" ARM int InitializeChannelIDsAndAllocateConfiguredResources(void* allocator) {
    int i=0;
    unsigned bytes;
    Channel* channel = data_02110a4c;
    do {
        unsigned char* config=GetBoundedRelocatedBlobIndexEntryFromHeader20(i);
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
