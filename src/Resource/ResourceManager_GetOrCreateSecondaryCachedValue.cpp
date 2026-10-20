#include <globaldefs.h>
extern "C" int NNS_SndArcGetFileAddress(void); extern "C" int NNS_SndArcGetCurrent(void);
extern "C" void SoundArchive_DisposeWaveArchiveFile(void); extern "C" int Filesystem_AllocateReadAndFlushFileBuffer(int,int,int,int,int);
extern "C" void NNS_SndArcSetFileAddress(int,int);
ARM
// Original: arm9/main @ 0x020BE280; symbol: func_020be280; size: 0x6C.
extern "C" int ResourceManager_GetOrCreateSecondaryCachedValue(int p1, int p2, int flags) {
    int result=NNS_SndArcGetFileAddress();
    if (result == 0) {
        int extra=(flags == 0) ? 0 : NNS_SndArcGetCurrent();
        result=Filesystem_AllocateReadAndFlushFileBuffer(p1,(int)&SoundArchive_DisposeWaveArchiveFile,extra,p1,p2);
        if (flags != 0 && result != 0) NNS_SndArcSetFileAddress(p1,result);
    }
    return result;
}
