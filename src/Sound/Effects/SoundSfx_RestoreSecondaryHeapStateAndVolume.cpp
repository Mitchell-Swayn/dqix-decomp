#include <globaldefs.h>
ARM
#pragma optimize_for_size off
extern "C" void ResourceHandle_RestoreArchiveHeapState(char*,unsigned);
extern "C" void SoundSfx_SetScaledPlayerVolumes(char*,unsigned);
extern "C" void Sound_UpdatePlaybackAndFlushCommands();
// Original: arm9/main @ 0x0205E8EC; symbol: func_0205e8ec; size: 0x40.
extern "C" void SoundSfx_RestoreSecondaryHeapStateAndVolume(char* p){
    if(*(unsigned*)(p+0xb8)){
        ResourceHandle_RestoreArchiveHeapState(p,*(unsigned*)(p+0xb8));
        *(unsigned*)(p+0xc0)=*(unsigned*)(p+0xb8);
        *(short*)(p+0xbc)=-1;
        *(short*)(p+0xc4)=-1;
    }
    SoundSfx_SetScaledPlayerVolumes(p,127);
    Sound_UpdatePlaybackAndFlushCommands();
}
