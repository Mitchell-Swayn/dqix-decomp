#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" int CountAllocatorEntriesWithKindOneAndMatchingId(int);
// Original: arm9/main @ 0x0209CA2C; symbol: func_0209ca2c; size: 0x3C.
extern "C" bool Bgm_IsTemporarySequencePendingOrPlaying(char* p){
    short id=*(short*)(p+0xce);
    if(id<0)return false;
    if(*(unsigned char*)(p+0xc9))return true;
    return CountAllocatorEntriesWithKindOneAndMatchingId(id)>0;
}
